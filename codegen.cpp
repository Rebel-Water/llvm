#include "codegen.hpp"
#include "llvm/IR/Verifier.h"

llvm::Value *Codegen::VisitProgram(Program *p)
{
    auto printfFuncType = llvm::FunctionType::get(irBuilder.getInt32Ty(), {irBuilder.getInt8PtrTy()}, true);
    auto printfFunc = llvm::Function::Create(printfFuncType, llvm::GlobalValue::ExternalLinkage, "printf", module.get());

    auto mFuncType = llvm::FunctionType::get(irBuilder.getInt32Ty(), false);
    auto mFunc = llvm::Function::Create(mFuncType, llvm::GlobalValue::ExternalLinkage, "main", module.get());
    auto entryBlock = llvm::BasicBlock::Create(context, "entry", mFunc);
    irBuilder.SetInsertPoint(entryBlock);

    llvm::Value* lastValue = nullptr;
    for (auto &node : p->astNodes)
        lastValue = node->Accept(this);

    irBuilder.CreateCall(printfFunc, {irBuilder.CreateGlobalString("expr val: %d\n"), lastValue});

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
    default:
        break;
    }
    return nullptr;
}

llvm::Value *Codegen::VisitAssignExpr(AssignExpr *expr)
{
    VariableAccessExpr* varAccessExpr = (VariableAccessExpr*)(expr->left.get());
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

llvm::Value *Codegen::VisitNumberExpr(NumberExpr *expr)
{
    return irBuilder.getInt32(expr->token.value);
}
