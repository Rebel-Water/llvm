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
    switch (binaryExpr->opcode)
    {
    case Opcode::add:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateNSWAdd(left, right);
    }
    case Opcode::sub:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateNSWSub(left, right);
    }
    case Opcode::mul:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateNSWMul(left, right);
    }
    case Opcode::div:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateSDiv(left, right);
    }
    case Opcode::mod:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateSRem(left, right);
    }
    case Opcode::bitAnd:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateAnd(left, right);
    }
    case Opcode::bitOr:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateOr(left, right);
    }
    case Opcode::bitXor:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateXor(left, right);
    }
    case Opcode::leftShift:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateShl(left, right);
    }
    case Opcode::rightShift:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        return irBuilder.CreateAShr(left, right);
    }

    case Opcode::equal_equal:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        llvm::Value *val = irBuilder.CreateICmpEQ(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::not_equal:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        llvm::Value *val = irBuilder.CreateICmpNE(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::less:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        llvm::Value *val = irBuilder.CreateICmpSLT(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::less_equal:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        llvm::Value *val = irBuilder.CreateICmpSLE(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::greater:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        llvm::Value *val = irBuilder.CreateICmpSGT(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::greater_equal:
    {
        auto left = binaryExpr->left->Accept(this);
        auto right = binaryExpr->right->Accept(this);
        llvm::Value *val = irBuilder.CreateICmpSGE(left, right);
        return irBuilder.CreateIntCast(val, irBuilder.getInt32Ty(), true);
    }
    case Opcode::logAnd:
    {
        /// A && B

        llvm::BasicBlock *nextBB = llvm::BasicBlock::Create(context, "nextBB", curFunc);
        llvm::BasicBlock *falseBB = llvm::BasicBlock::Create(context, "falseBB");
        llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(context, "mergeBB");

        llvm::Value *left = binaryExpr->left->Accept(this);
        llvm::Value *val = irBuilder.CreateICmpNE(left, irBuilder.getInt32(0));
        irBuilder.CreateCondBr(val, nextBB, falseBB);

        irBuilder.SetInsertPoint(nextBB);
        llvm::Value *right = binaryExpr->right->Accept(this);
        right = irBuilder.CreateICmpNE(right, irBuilder.getInt32(0));
        /// 32位 0 或着 1
        right = irBuilder.CreateZExt(right, irBuilder.getInt32Ty());
        irBuilder.CreateBr(mergeBB);

        /// right 这个值，所在的基本块，并不一定是 之前的nextBB了.
        /// 原因是：binaryExpr->right->Accept(this) 内部会生成新的基本块

        /// 拿到当前插入的block, 建立一个值和基本块的关系 {right, nextBB}
        nextBB = irBuilder.GetInsertBlock();

        falseBB->insertInto(curFunc);
        irBuilder.SetInsertPoint(falseBB);
        irBuilder.CreateBr(mergeBB);

        mergeBB->insertInto(curFunc);
        irBuilder.SetInsertPoint(mergeBB);
        llvm::PHINode *phi = irBuilder.CreatePHI(irBuilder.getInt32Ty(), 2);
        phi->addIncoming(right, nextBB);
        phi->addIncoming(irBuilder.getInt32(0), falseBB);

        return phi;
    }
    case Opcode::logOr:
    {
        /// A || B && C

        llvm::BasicBlock *nextBB = llvm::BasicBlock::Create(context, "nextBB", curFunc);
        llvm::BasicBlock *trueBB = llvm::BasicBlock::Create(context, "trueBB");
        llvm::BasicBlock *mergeBB = llvm::BasicBlock::Create(context, "mergeBB");

        llvm::Value *left = binaryExpr->left->Accept(this);
        llvm::Value *val = irBuilder.CreateICmpNE(left, irBuilder.getInt32(0));
        irBuilder.CreateCondBr(val, trueBB, nextBB);

        irBuilder.SetInsertPoint(nextBB);
        /// 右子树内部也生成了基本块
        llvm::Value *right = binaryExpr->right->Accept(this);
        right = irBuilder.CreateICmpNE(right, irBuilder.getInt32(0));
        /// 32位 0 或着 1
        right = irBuilder.CreateZExt(right, irBuilder.getInt32Ty());
        irBuilder.CreateBr(mergeBB);
        /// right 这个值，所在的基本块，并不一定是 之前的nextBB了.
        /// 原因是：binaryExpr->right->Accept(this) 内部会生成新的基本块

        /// 拿到当前插入的block, 建立一个值和基本块的关系 {right, nextBB}
        nextBB = irBuilder.GetInsertBlock();

        trueBB->insertInto(curFunc);
        irBuilder.SetInsertPoint(trueBB);
        irBuilder.CreateBr(mergeBB);

        mergeBB->insertInto(curFunc);
        irBuilder.SetInsertPoint(mergeBB);
        llvm::PHINode *phi = irBuilder.CreatePHI(irBuilder.getInt32Ty(), 2);
        phi->addIncoming(right, nextBB);
        phi->addIncoming(irBuilder.getInt32(1), trueBB);

        return phi;
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

llvm::Value *Codegen::VisitForStmt(ForStmt *stmt)
{
    auto initBB = llvm::BasicBlock::Create(context, "for.init", curFunc);
    auto condBB = llvm::BasicBlock::Create(context, "for.cond", curFunc);
    auto incBB = llvm::BasicBlock::Create(context, "for.inc", curFunc);
    auto bodyBB = llvm::BasicBlock::Create(context, "for.body", curFunc);
    auto lastBB = llvm::BasicBlock::Create(context, "for.last", curFunc);

    breakBBs.insert({stmt, lastBB});
    continueBBs.insert({stmt, incBB});

    irBuilder.CreateBr(initBB);
    irBuilder.SetInsertPoint(initBB);

    if (stmt->init)
        stmt->init->Accept(this);

    irBuilder.CreateBr(condBB);
    irBuilder.SetInsertPoint(condBB);

    if (stmt->cond)
    {
        auto val = stmt->cond->Accept(this);
        auto condVal = irBuilder.CreateICmpNE(val, irBuilder.getInt32(0));
        irBuilder.CreateCondBr(condVal, bodyBB, lastBB);
    }
    else
    {
        irBuilder.CreateBr(bodyBB);
    }
    irBuilder.SetInsertPoint(bodyBB);
    if (stmt->body)
    {
        stmt->body->Accept(this);
    }
    irBuilder.CreateBr(incBB);

    irBuilder.SetInsertPoint(incBB);

    if (stmt->inc)
        stmt->inc->Accept(this);

    irBuilder.CreateBr(condBB);

    breakBBs.erase(stmt);
    continueBBs.erase(stmt);
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

llvm::Value *Codegen::VisitBreakStmt(BreakStmt *stmt)
{
    auto bb = breakBBs[stmt->target.get()];
    irBuilder.CreateBr(bb);

    auto out = llvm::BasicBlock::Create(context, "for.break.death", curFunc);
    irBuilder.SetInsertPoint(out);
    return nullptr;
}

llvm::Value *Codegen::VisitContinueStmt(ContinueStmt *stmt)
{
    auto bb = continueBBs[stmt->target.get()];
    irBuilder.CreateBr(bb);
    auto out = llvm::BasicBlock::Create(context, "for.continue.death", curFunc);
    irBuilder.SetInsertPoint(out);
    return nullptr;
}

llvm::Value *Codegen::VisitNumberExpr(NumberExpr *expr)
{
    return irBuilder.getInt32(expr->token.value);
}
