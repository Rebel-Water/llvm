#include "codegen.hpp"
#include "llvm/IR/Verifier.h"

llvm::Value* Codegen::VisitrProgram(Program *p)
{
    auto printfFuncType = llvm::FunctionType::get(irBuilder.getInt32Ty(), {irBuilder.getInt8PtrTy()}, true);
    auto printfFunc = llvm::Function::Create(printfFuncType, llvm::GlobalValue::ExternalLinkage, "printf", module.get());

    auto mFuncType = llvm::FunctionType::get(irBuilder.getInt32Ty(), false);
    auto mFunc = llvm::Function::Create(mFuncType, llvm::GlobalValue::ExternalLinkage, "main", module.get());
    auto entryBlock = llvm::BasicBlock::Create(context, "entry", mFunc);
    irBuilder.SetInsertPoint(entryBlock);

    for(auto& expr : p->exprVec) {
        auto p = expr->Accept(this);
        irBuilder.CreateCall(printfFunc, {irBuilder.CreateGlobalStringPtr("expr val: %d\n"), p});
    }
    
    auto ret = irBuilder.CreateRet(irBuilder.getInt32(0));
    llvm::verifyFunction(*mFunc);

    module->print(llvm::outs(), nullptr);
    return ret;
}

llvm::Value* Codegen::VisitBinaryExpr(BinaryExpr *binaryExpr)
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
    return nullptr;
}

llvm::Value *Codegen::VisitVariableDecl(VariableDecl *decl)
{
    return nullptr;
}

llvm::Value *Codegen::VisitVariableAccessExpr(VariableAccessExpr *expr)
{
    return nullptr;
}

llvm::Value* Codegen::VisitNumberExpr(NumberExpr* expr)
{
    return irBuilder.getInt32(expr->value);
}
