#pragma once
#include <memory>
#include <vector>
#include "llvm/IR/Value.h"
#include "type.hpp"
#include "lexer.hpp"

struct Program;
struct AstNode;
struct BinaryExpr;
struct NumberExpr;
struct AssignExpr;
struct VariableDecl;
struct VariableAccessExpr;
struct IfStmt;
struct DeclStmt;
struct BlockStmt;

class Visitor {
    public:
    virtual ~Visitor() = default;
    virtual llvm::Value* VisitProgram(Program* p) = 0;
    virtual llvm::Value* VisitAstNode(AstNode* node) { return nullptr; }
    virtual llvm::Value* VisitBinaryExpr(BinaryExpr* expr) = 0; 
    virtual llvm::Value* VisitNumberExpr(NumberExpr* expr) = 0;
    virtual llvm::Value* VisitAssignExpr(AssignExpr* expr) = 0;
    virtual llvm::Value* VisitVariableDecl(VariableDecl* expr) = 0;
    virtual llvm::Value* VisitIfStmt(IfStmt* stmt) = 0;
    virtual llvm::Value* VisitDeclStmt(DeclStmt* stmt) = 0;
    virtual llvm::Value* VisitBlockStmt(BlockStmt* stmt) = 0;
    virtual llvm::Value* VisitVariableAccessExpr(VariableAccessExpr* expr) = 0;
};

enum class Opcode {
    add,
    sub,
    mul,
    div,
    equal_equal,
    not_equal,
    less_equal,
    less,
    greater,
    greater_equal,
};

// llvm rtti
struct AstNode {
    enum Kind {
        ND_VariableDecl,
        ND_BinaryExpr,
        ND_NumberExpr,
        ND_VariableAccessExpr,
        ND_Assign,
        ND_IfStmt,
        ND_DeclStmt,
        ND_BlockStmt,
    };
    AstNode(const Kind& kind) : kind(kind) {}
    virtual ~AstNode() {}
    virtual llvm::Value *Accept(Visitor* v) { return nullptr; }
    CType* ty;
    const Kind kind;
};

struct BlockStmt : AstNode {
    std::vector<std::shared_ptr<AstNode>> astVec;
    BlockStmt() : AstNode(ND_BlockStmt) {}
    virtual llvm::Value *Accept(Visitor* v) { return v->VisitBlockStmt(this); }
    static bool classof(const AstNode* node) {
        return node->kind == ND_BlockStmt;
    }
};

struct DeclStmt : AstNode {
    std::vector<std::shared_ptr<AstNode>> astVec;
    DeclStmt() : AstNode(ND_DeclStmt) {}
    virtual llvm::Value *Accept(Visitor* v) { return v->VisitDeclStmt(this); }
    static bool classof(const AstNode* node) {
        return node->kind == ND_DeclStmt;
    }
};

struct IfStmt : AstNode {
    std::shared_ptr<AstNode> condNode;
    std::shared_ptr<AstNode> thenNode;
    std::shared_ptr<AstNode> elseNode;
    IfStmt() : AstNode(ND_IfStmt) {}
    virtual llvm::Value *Accept(Visitor* v) { return v->VisitIfStmt(this); }
    static bool classof(const AstNode* node) {
        return node->kind == ND_IfStmt;
    }
};

struct VariableDecl : AstNode {
    Token token;
    VariableDecl() : AstNode(ND_VariableDecl) {}
    virtual llvm::Value *Accept(Visitor* v) { return v->VisitVariableDecl(this); }
    static bool classof(const AstNode* node) {
        return node->kind == ND_VariableDecl;
    }
};

struct BinaryExpr : AstNode {
    Opcode opcode;
    std::shared_ptr<AstNode> left;
    std::shared_ptr<AstNode> right;
    BinaryExpr() : AstNode(ND_BinaryExpr) {}
    virtual llvm::Value* Accept(Visitor* v) override {
        return v->VisitBinaryExpr(this);
    }
    static bool classof(const AstNode* node) {
        return node->kind == ND_BinaryExpr;
    }
};

struct NumberExpr : AstNode {
    Token token;
    virtual llvm::Value* Accept(Visitor* v) override {
        return v->VisitNumberExpr(this);
    }
    NumberExpr() : AstNode(ND_NumberExpr) {}
    static bool classof(const AstNode* node) {
        return node->kind == ND_NumberExpr;
    }
};

struct VariableAccessExpr : AstNode {
    Token token;
    VariableAccessExpr() : AstNode(ND_VariableAccessExpr) {}
    static bool classof(const AstNode* node) {
        return node->kind == ND_VariableAccessExpr;
    }
    virtual llvm::Value* Accept(Visitor* v) override {
        return v->VisitVariableAccessExpr(this);
    }
};

struct AssignExpr : AstNode {
    std::shared_ptr<AstNode> left;
    std::shared_ptr<AstNode> right;
    AssignExpr() : AstNode(ND_Assign) {}
    static bool classof(const AstNode* node) {
        return node->kind == ND_Assign;
    }
    virtual llvm::Value* Accept(Visitor* v) override {
        return v->VisitAssignExpr(this);
    }
};

struct Program {
    std::vector<std::shared_ptr<AstNode>> astNodes;
    virtual llvm::Value* Accept(Visitor* v) {
        return v->VisitProgram(this);
    }
};