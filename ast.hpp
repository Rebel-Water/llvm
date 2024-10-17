#pragma once
#include <memory>
#include <vector>

struct Program;
struct Expr;
struct BinaryExpr;
struct FactorExpr;

struct Visitor {
    virtual ~Visitor() {}
    virtual void VisitrProgram(Program* p) = 0;
    virtual void VisitExpr(Expr* expr) {}
    virtual void VisitBinaryExpr(BinaryExpr* binaryExpr) = 0; 
    virtual void VisitFactorExpr(FactorExpr* factorExpr) = 0;
};

enum class Opcode {
    add,
    sub,
    mul,
    div,
};

struct Expr {
    virtual ~Expr() {}
    virtual void Accept(Visitor* v) {}
};

struct BinaryExpr : Expr{
    Opcode opcode;
    std::shared_ptr<Expr> left;
    std::shared_ptr<Expr> right;
    virtual void Accept(Visitor* v) override {
        v->VisitBinaryExpr(this);
    }
};

struct FactorExpr : Expr{
    int value;
    virtual void Accept(Visitor* v) override {
        v->VisitFactorExpr(this);
    }
};

struct Program {
    std::vector<std::shared_ptr<Expr>> exprVec;
    virtual void Accept(Visitor* v) {
        v->VisitrProgram(this);
    }
};