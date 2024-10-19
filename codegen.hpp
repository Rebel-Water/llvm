#pragma once
#include "ast.hpp"
#include "parser.hpp"
#include <memory>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"

class Codegen : Visitor {
public:
    Codegen(std::shared_ptr<Program> p) {
        module = std::make_shared<llvm::Module>("expr", context);
        VisitrProgram(p.get());
    }
private:
    virtual llvm::Value* VisitrProgram(Program* p) override;
    virtual llvm::Value* VisitBinaryExpr(BinaryExpr* binaryExpr) override; 
    virtual llvm::Value* VisitFactorExpr(FactorExpr* factorExpr) override;

    llvm::LLVMContext context;
    llvm::IRBuilder<> irBuilder{context};
    std::shared_ptr<llvm::Module> module;
};