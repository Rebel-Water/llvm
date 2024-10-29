#include "codegen.hpp"
#include "llvm/IR/Verifier.h"

llvm::Value *Codegen::VisitProgram(Program *p)
{
    auto printfFuncType = llvm::FunctionType::get(irBuilder.getInt32Ty(), {irBuilder.getInt8PtrTy()}, true);
    auto printfFunc = llvm::Function::Create(printfFuncType, llvm::GlobalValue::ExternalLinkage, "printf", module.get());

    auto mFuncType = llvm::FunctionType::get(irBuilder.getInt32Ty(), false);
    auto mFunc = llvm::Function::Create(mFuncType, llvm::GlobalValue::ExternalLinkage, "main", module.get());

    curFunc = mFunc;

    auto entryBlock = llvm::BasicBlock::Create(context, "entry", mFunc);
    irBuilder.SetInsertPoint(entryBlock);

    llvm::Value *lastValue = nullptr;
    for (auto &node : p->astNodes)
        lastValue = node->Accept(this);

    if (lastValue)
        irBuilder.CreateCall(printfFunc, {irBuilder.CreateGlobalString("expr val: %d\n"), lastValue});
    else
        irBuilder.CreateCall(printfFunc, {irBuilder.CreateGlobalString("last instruction is not expression.")});

    auto ret = irBuilder.CreateRet(irBuilder.getInt32(0));
    llvm::verifyFunction(*mFunc);

    module->print(llvm::outs(), nullptr);
    return ret;
}

llvm::Value *Codegen::VisitBinaryExpr(BinaryExpr *binaryExpr)
{
    auto left = binaryExpr->left->Accept(this);
    auto right = binaryExpr->right->Accept(this);
    switch (binaryExpr->opcode)
    {
    case Opcode::add:
        return irBuilder.CreateNSWAdd(left, right);
    case Opcode::sub:
        return irBuilder.CreateNSWSub(left, right);
    case Opcode::mul:
        return irBuilder.CreateNSWMul(left, right);
    case Opcode::div:
        return irBuilder.CreateSDiv(left, right);

    case Opcode::equal_equal:
    {
        /// getIntTy()
        llvm::Value *val = irBuilder.CreateICmpEQ(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::not_equal:
    {
        llvm::Value *val = irBuilder.CreateICmpNE(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::less:
    {
        llvm::Value *val = irBuilder.CreateICmpSLT(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::less_equal:
    {
        llvm::Value *val = irBuilder.CreateICmpSLE(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::greater:
    {
        llvm::Value *val = irBuilder.CreateICmpSGT(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::greater_equal:
    {
        llvm::Value *val = irBuilder.CreateICmpSGE(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    default:
        break;
    }
    return nullptr;
}

llvm::Value *Codegen::VisitAssignExpr(AssignExpr *expr)
{
    VariableAccessExpr *varAccessExpr = (VariableAccessExpr *)(expr->left.get());
    llvm::StringRef text(varAccessExpr->token.ptr, varAccessExpr->token.len);
    auto pair = varAddrTypeMap[text];
    auto addr = pair.first;
    auto ty = pair.second;

    auto rightValue = expr->right->Accept(this);
    irBuilder.CreateStore(rightValue, addr);
    return irBuilder.CreateLoad(ty, addr, text);
}

llvm::Value *Codegen::VisitVariableDecl(VariableDecl *decl)
{
    llvm::Type *ty = nullptr;
    if (decl->ty == CType::GetIntTy())
        ty = irBuilder.getInt32Ty();
    llvm::StringRef text(decl->token.ptr, decl->token.len);
    llvm::Value *value = irBuilder.CreateAlloca(ty, nullptr, text);
    varAddrTypeMap.insert({text, std::make_pair(value, ty)});
    return value;
}

llvm::Value *Codegen::VisitVariableAccessExpr(VariableAccessExpr *expr)
{
    llvm::StringRef text(expr->token.ptr, expr->token.len);
    auto pair = varAddrTypeMap[text];
    llvm::Value *varAddr = pair.first;
    llvm::Type *ty = pair.second;
    return irBuilder.CreateLoad(ty, varAddr, text);
}

llvm::Value *Codegen::VisitDeclStmt(DeclStmt *stmt)
{
    llvm::Value *lastVal = nullptr;
    for (const auto &node : stmt->astVec)
        lastVal = node->Accept(this);
    return lastVal;
}

llvm::Value *Codegen::VisitIfStmt(IfStmt *stmt)
{
    llvm::BasicBlock *condBB = llvm::BasicBlock::Create(context, "cond", curFunc);
    llvm::BasicBlock *thenBB = llvm::BasicBlock::Create(context, "then", curFunc);
    llvm::BasicBlock *elseBB = nullptr;
    if (stmt->elseNode)
        elseBB = llvm::BasicBlock::Create(context, "else", curFunc);
    llvm::BasicBlock *lastBB = llvm::BasicBlock::Create(context, "last", curFunc);

    irBuilder.CreateBr(condBB);
    irBuilder.SetInsertPoint(condBB);
    llvm::Value *val = stmt->condNode->Accept(this);

    llvm::Value *condVal = irBuilder.CreateICmpNE(val, irBuilder.getInt32(0));
    if (stmt->elseNode)
    {
        irBuilder.CreateCondBr(condVal, thenBB, elseBB);
        irBuilder.SetInsertPoint(thenBB);
        stmt->thenNode->Accept(this);
        irBuilder.CreateBr(lastBB); // lastBB is a unconditional label

        irBuilder.SetInsertPoint(elseBB);
        stmt->elseNode->Accept(this);
        irBuilder.CreateBr(lastBB);
    }
    else
    {
        irBuilder.CreateCondBr(condVal, thenBB, lastBB);
        irBuilder.SetInsertPoint(thenBB);
        stmt->thenNode->Accept(this);
        irBuilder.CreateBr(lastBB);
    }
    irBuilder.SetInsertPoint(lastBB);
    return nullptr;
}

llvm::Value *Codegen::VisitBlockStmt(BlockStmt *stmts)
{
    llvm::Value *lastVal = nullptr;
    for (const auto &stmt : stmts->astVec)
        lastVal = stmt->Accept(this);
    return lastVal;
}

llvm::Value *Codegen::VisitNumberExpr(NumberExpr *expr)
{
    return irBuilder.getInt32(expr->token.value);
}
