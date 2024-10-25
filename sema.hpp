#pragma once
#include "scope.hpp"
#include "ast.hpp"
#include "diag_engine.hpp"
#include <memory>
struct Sema {
    DiagEngine& diag;
    Sema(DiagEngine& diag) : diag(diag) {}

    std::shared_ptr<AstNode> SemaVarDeclNode(Token token, CType* ty);
    std::shared_ptr<AstNode> SemaAssignExprNode(std::shared_ptr<AstNode> left, std::shared_ptr<AstNode> right, Token token);
    std::shared_ptr<AstNode> SemaVarAccessNode(Token token);
    std::shared_ptr<AstNode> SemaNumberNode(Token token, CType* ty);
    std::shared_ptr<AstNode> SemaBinaryExprNode(std::shared_ptr<AstNode> left, std::shared_ptr<AstNode> right, Opcode op);
    Scope scope;

};