#pragma once
#include "ast.hpp"
#include "parser.hpp"
struct PrintVisitor : Visitor {
    PrintVisitor(std::shared_ptr<Program> program);
    virtual llvm::Value* VisitrProgram(Program* p);
    virtual llvm::Value* VisitBinaryExpr(BinaryExpr* binaryExpr); 
    virtual llvm::Value* VisitFactorExpr(FactorExpr* factorExpr);
};
