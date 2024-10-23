#pragma once
#include "ast.hpp"
#include "parser.hpp"
#include <memory>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/IRBuilder.h"
#include <utility>
class Codegen : Visitor {
public:
    Codegen(std::shared_ptr<Program> p) {
        module = std::make_shared<llvm::Module>("variable", context);
        VisitProgram(p.get());
    }
private:
    virtual llvm::Value* VisitProgram(Program* p) override;
    virtual llvm::Value* VisitBinaryExpr(BinaryExpr* expr) override; 
    virtual llvm::Value* VisitNumberExpr(NumberExpr* expr) override;
    virtual llvm::Value* VisitAssignExpr(AssignExpr* expr) override;
    virtual llvm::Value* VisitVariableDecl(VariableDecl* decl) override;
    virtual llvm::Value* VisitVariableAccessExpr(VariableAccessExpr* expr) override;

    llvm::LLVMContext context;
    llvm::IRBuilder<> irBuilder{context};
    std::shared_ptr<llvm::Module> module;

    llvm::StringMap<std::pair<llvm::Value*, llvm::Type*>> varAddrTypeMap;
};