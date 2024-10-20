#include "sema.hpp"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Casting.h"

std::shared_ptr<AstNode> Sema::SemaVarDeclNode(llvm::StringRef name, CType *ty)
{
    auto symbol = scope.FindVarSymbolInCurEnv(name);
    if (symbol)
    {
        llvm::errs() << "redefined variable" << name << "\n";
        return nullptr;
    }

    scope.AddSymbol(SymbolKind::LocalVariable, ty, name);

    auto variableDecl = std::make_shared<VariableDecl>();
    variableDecl->name = name;
    variableDecl->ty = ty;

    return variableDecl;
}

std::shared_ptr<AstNode> Sema::SemaAssignExprNode(std::shared_ptr<AstNode> left, std::shared_ptr<AstNode> right)
{
    if(left == nullptr || right == nullptr) {
        llvm::errs() << "left or right cannot be nullptr\n";
        return nullptr;
    }

    if(!llvm::isa<VariableAccessExpr>(left.get())) {
        llvm::errs() << "must be left value\n";
        return nullptr;
    }

    auto assignExpr = std::make_shared<AssignExpr>();
    assignExpr->left = left;
    assignExpr->right = right;
    return assignExpr;
}

std::shared_ptr<AstNode> Sema::SemaVarAccessNode(llvm::StringRef name)
{
    auto symbol = scope.FindVarSymbol(name);
    if (symbol == nullptr)
    {
        llvm::errs() << "use undefined variable" << name << "\n";
        return nullptr;
    }

    auto accessExpr = std::make_shared<VariableAccessExpr>();
    accessExpr->name = name;
    accessExpr->ty = symbol->ty;

    return accessExpr;
}

std::shared_ptr<AstNode> Sema::SemaNumberNode(int number, CType *ty)
{
    auto factor = std::make_shared<NumberExpr>();
    factor->value = number;
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
