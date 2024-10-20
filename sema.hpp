#pragma once
#include "scope.hpp"
#include "ast.hpp"
#include <memory>
struct Sema {
    std::shared_ptr<AstNode> SemaVarDeclNode(llvm::StringRef name, CType* ty);
    std::shared_ptr<AstNode> SemaAssignExprNode(std::shared_ptr<AstNode> left, std::shared_ptr<AstNode> right);
    std::shared_ptr<AstNode> SemaVarAccessNode(llvm::StringRef name);
    std::shared_ptr<AstNode> SemaNumberNode(int number, CType* ty);
    std::shared_ptr<AstNode> SemaBinaryExprNode(std::shared_ptr<AstNode> left, std::shared_ptr<AstNode> right, Opcode op);
    Scope scope;

};