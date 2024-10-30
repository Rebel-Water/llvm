#pragma once
#include "ast.hpp"
#include "parser.hpp"
struct PrintVisitor : Visitor {
    PrintVisitor(std::shared_ptr<Program> program);
    virtual llvm::Value* VisitProgram(Program* p);
    virtual llvm::Value* VisitBinaryExpr(BinaryExpr* binaryExpr); 
    virtual llvm::Value* VisitNumberExpr(NumberExpr* numberExpr);
    virtual llvm::Value* VisitAssignExpr(AssignExpr* assignExpr);
    virtual llvm::Value* VisitVariableDecl(VariableDecl* variableDecl);
    virtual llvm::Value* VisitVariableAccessExpr(VariableAccessExpr* variableAccessExpr);
    virtual llvm::Value* VisitIfStmt(IfStmt* stmt);
    virtual llvm::Value* VisitForStmt(ForStmt* stmt);
    virtual llvm::Value *VisitBreakStmt(BreakStmt *stmt);
    virtual llvm::Value *VisitContinueStmt(ContinueStmt *stmt);
    virtual llvm::Value* VisitDeclStmt(DeclStmt* stmt);
    virtual llvm::Value* VisitBlockStmt(BlockStmt* stmt);
};
