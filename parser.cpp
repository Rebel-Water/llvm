#include "parser.hpp"
#include <cassert>

std::vector<std::shared_ptr<AstNode>> Parser::PasreDecl()
{
    Consume(TokenType::kw_int);
    CType *baseTy = CType::GetIntTy();
    std::vector<std::shared_ptr<AstNode>> astArr;

    while (current.tokenType != TokenType::semi)
    {

        auto variableDecl = std::make_shared<VariableDecl>();
        variableDecl->name = current.context;
        variableDecl->ty = baseTy;
        astArr.push_back(variableDecl);
        Consume(TokenType::identifier);

        if (current.tokenType == TokenType::equal)
        {
            Advance();
            auto right = ParseExpr();
            auto assignExpr = std::make_shared<AssignExpr>();
            auto accessExpr = std::make_shared<VariableAccessExpr>();

            accessExpr->name = variableDecl->name;
            assignExpr->left = accessExpr;

            assignExpr->right = right;

            astArr.push_back(assignExpr);
        }
        if (Expect(TokenType::comma))
            Advance();
    }
    Consume(TokenType::semi);
    return astArr;
}

std::shared_ptr<AstNode> Parser::ParseFactor()
{
    if (current.tokenType == TokenType::l_parent)
    {
        Advance();
        auto expr = ParseExpr();
        assert(Expect(TokenType::r_parent));
        Advance();
        return expr;
    }
    else if (current.tokenType == TokenType::identifier)
    {
        auto expr = std::make_shared<VariableAccessExpr>();
        expr->name = current.context;
        Advance();
        return expr;
    }
    else
    {
        auto factor = std::make_shared<NumberExpr>();
        factor->value = current.value;
        factor->ty = current.ty;
        Advance();
        return factor;
    }
}

std::shared_ptr<AstNode> Parser::ParseExpr()
{
    auto left = ParseTerm();
    while (current.tokenType == TokenType::minus || current.tokenType == TokenType::plus)
    {
        Opcode op;
        if (current.tokenType == TokenType::plus)
            op = Opcode::add;
        else
            op = Opcode::sub;
        Advance();
        auto binaryAstNode = std::make_shared<BinaryExpr>();
        binaryAstNode->opcode = op;
        binaryAstNode->left = left;
        binaryAstNode->right = ParseTerm();
        left = binaryAstNode;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseTerm()
{
    auto left = ParseFactor();
    while (current.tokenType == TokenType::star || current.tokenType == TokenType::slash)
    {
        Opcode op;
        if (current.tokenType == TokenType::star)
            op = Opcode::mul;
        else
            op = Opcode::div;
        Advance();
        auto binaryAstNode = std::make_shared<BinaryExpr>();
        binaryAstNode->opcode = op;
        binaryAstNode->left = left;
        binaryAstNode->right = ParseFactor();
        left = binaryAstNode;
    }
    return left;
}

std::shared_ptr<Program> Parser::ParseProgram()
{
    std::vector<std::shared_ptr<AstNode>> exprVec;
    while (current.tokenType != TokenType::eof)
    {
        if (current.tokenType == TokenType::semi)
        {
            Advance();
            continue;
        }
        if (current.tokenType == TokenType::kw_int)
        {
            const auto &exprs = PasreDecl();
            for (auto &expr : exprs)
                exprVec.push_back(expr);
        }
        else
        {
            auto expr = ParseExpr();
            exprVec.push_back(expr);
        }
    }
    auto program = std::make_shared<Program>();
    program->exprVec = std::move(exprVec);
    return program;
}

bool Parser::Expect(TokenType tokenType)
{
    return current.tokenType == tokenType;
}

void Parser::Advance()
{
    lexer.NextToken(current);
}

bool Parser::Consume(TokenType tokenType)
{
    if (current.tokenType == tokenType)
    {
        Advance();
        return true;
    }
    return false;
}
