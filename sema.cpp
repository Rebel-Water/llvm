#include "sema.hpp"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Casting.h"
#include "lexer.hpp"

std::shared_ptr<AstNode> Sema::SemaVarDeclNode(Token token, CType *ty)
{
    llvm::StringRef text(token.ptr, token.len);
    auto symbol = scope.FindVarSymbolInCurEnv(text);
    if (symbol)
    {
        diag.Report(llvm::SMLoc::getFromPointer(token.ptr), diag::err_redefined, text);
    }

    scope.AddSymbol(SymbolKind::LocalVariable, ty, text);

    auto variableDecl = std::make_shared<VariableDecl>();
    variableDecl->token = token;
    variableDecl->ty = ty;

    return variableDecl;
}

std::shared_ptr<AstNode> Sema::SemaAssignExprNode(std::shared_ptr<AstNode> left, std::shared_ptr<AstNode> right, Token token)
{
    assert(left && right);
    llvm::StringRef text(token.ptr, token.len);

    if(!llvm::isa<VariableAccessExpr>(left.get())) {
        diag.Report(llvm::SMLoc::getFromPointer(token.ptr), diag::err_lvalue, text);
    }

    auto assignExpr = std::make_shared<AssignExpr>();
    assignExpr->left = left;
    assignExpr->right = right;
    return assignExpr;
}

std::shared_ptr<AstNode> Sema::SemaVarAccessNode(Token token)
{
    llvm::StringRef text(token.ptr, token.len);
    auto symbol = scope.FindVarSymbol(text);
    if (symbol == nullptr)
    {
        diag.Report(llvm::SMLoc::getFromPointer(token.ptr), diag::err_undefined, text);
    }

    auto accessExpr = std::make_shared<VariableAccessExpr>();
    accessExpr->token = token;
    accessExpr->ty = symbol->ty;

    return accessExpr;
}

std::shared_ptr<AstNode> Sema::SemaNumberNode(Token token, CType *ty)
{
    auto factor = std::make_shared<NumberExpr>();
    factor->token = token;
    factor->ty = ty;
    return factor;
}

std::shared_ptr<AstNode> Sema::SemaBinaryExprNode(std::shared_ptr<AstNode> left, std::shared_ptr<AstNode> right, Opcode op)
{
    auto binary = std::make_shared<BinaryExpr>();
    binary->left = left;
    binary->right = right;
    binary->opcode = op;
    return binary;
}
