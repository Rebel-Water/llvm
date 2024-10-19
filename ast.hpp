#pragma once
#include <memory>
#include <vector>
#include "llvm/IR/Value.h"

struct Program;
struct Expr;
struct BinaryExpr;
struct FactorExpr;

class Visitor {
    public:
    virtual ~Visitor() = default;
    virtual llvm::Value* VisitrProgram(Program* p) = 0;
    virtual llvm::Value* VisitExpr(Expr* expr) { return nullptr; }
    virtual llvm::Value* VisitBinaryExpr(BinaryExpr* binaryExpr) = 0; 
    virtual llvm::Value* VisitFactorExpr(FactorExpr* factorExpr) = 0;
};

enum class Opcode {
    add,
    sub,
    mul,
    div,
};

struct Expr {
    virtual llvm::Value* Accept(Visitor* v) = 0;
};

struct BinaryExpr : Expr{
    Opcode opcode;
    std::shared_ptr<Expr> left;
    std::shared_ptr<Expr> right;
    virtual llvm::Value* Accept(Visitor* v) override {
        return v->VisitBinaryExpr(this);
    }
};

struct FactorExpr : Expr{
    int value;
    virtual llvm::Value* Accept(Visitor* v) override {
        return v->VisitFactorExpr(this);
    }
};

struct Program {
    std::vector<std::shared_ptr<Expr>> exprVec;
    virtual llvm::Value* Accept(Visitor* v) {
        return v->VisitrProgram(this);
    }
};