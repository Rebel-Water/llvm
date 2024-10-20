#pragma once
#include "ast.hpp"
#include "parser.hpp"
struct PrintVisitor : Visitor {
    PrintVisitor(std::shared_ptr<Program> program);
    virtual llvm::Value* VisitrProgram(Program* p);
    virtual llvm::Value* VisitBinaryExpr(BinaryExpr* binaryExpr); 
    virtual llvm::Value* VisitNumberExpr(NumberExpr* numberExpr);
    virtual llvm::Value* VisitAssignExpr(AssignExpr* assignExpr);
    virtual llvm::Value* VisitVariableDecl(VariableDecl* variableDecl);
    virtual llvm::Value* VisitVariableAccessExpr(VariableAccessExpr* variableAccessExpr);
};
