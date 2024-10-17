#pragma once
#include "ast.hpp"
#include "parser.hpp"
struct PrintVisitor : Visitor {
    PrintVisitor(std::shared_ptr<Program> program);
    virtual void VisitrProgram(Program* p);
    virtual void VisitBinaryExpr(BinaryExpr* binaryExpr); 
    virtual void VisitFactorExpr(FactorExpr* factorExpr);
};
