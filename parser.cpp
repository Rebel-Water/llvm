#include "parser.hpp"
#include <cassert>

std::shared_ptr<Expr> Parser::ParseFactor()
{
    if(current.tokenType == TokenType::l_parent) {
        Advance();
        auto expr = ParseExpr();
        assert(!Expect(TokenType::r_parent));
        Advance();
        return expr;
    } else {
        auto factor = std::make_shared<FactorExpr>();
        factor->value = current.value;
        Advance();
        return factor;
    }
}

std::shared_ptr<Expr> Parser::ParseExpr()
{
    auto left = ParseTerm();
    while(current.tokenType == TokenType::minus || current.tokenType == TokenType::plus) {
        Opcode op;
        if(current.tokenType == TokenType::plus)
            op = Opcode::add;
        else
            op = Opcode::sub;
        Advance();
        auto binaryExpr = std::make_shared<BinaryExpr>();
        binaryExpr->opcode = op;
        binaryExpr->left = left;
        binaryExpr->right = ParseTerm();
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<Expr> Parser::ParseTerm()
{
    auto left = ParseFactor();
    while(current.tokenType == TokenType::star|| current.tokenType == TokenType::slash) {
        Opcode op;
        if(current.tokenType == TokenType::star)
            op = Opcode::mul;
        else
            op = Opcode::div;
        Advance();
        auto binaryExpr = std::make_shared<BinaryExpr>();
        binaryExpr->opcode = op;
        binaryExpr->left = left;
        binaryExpr->right = ParseFactor();
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<Program> Parser::ParseProgram()
{
    std::vector<std::shared_ptr<Expr>> exprVec;
    while (current.tokenType != TokenType::eof)
    {
        if (current.tokenType == TokenType::semi)
        {
            Advance();
            continue;
        }
        auto expr = ParseExpr();
        exprVec.push_back(expr);
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
    if(current.tokenType == tokenType) {
        Advance();
        return true;
    }
    return false;
}
