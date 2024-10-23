#include "parser.hpp"
#include <cassert>

std::vector<std::shared_ptr<AstNode>> Parser::PasreDeclStmt()
{
    Consume(TokenType::kw_int);
    CType *baseTy = CType::GetIntTy();
    std::vector<std::shared_ptr<AstNode>> astArr;

    while (current.tokenType != TokenType::semi)
    {
        auto variableName = current.context;
        auto variableDecl = sema.SemaVarDeclNode(variableName, baseTy);
        astArr.push_back(variableDecl);
        Consume(TokenType::identifier);

        // int a = 1, b = 2; => int a; a = 1; int b; b = 2;
        if (current.tokenType == TokenType::equal)
        {
            Advance();
            auto left = sema.SemaVarAccessNode(variableName);
            auto right = ParseExpr();
            auto assignExpr = sema.SemaAssignExprNode(left, right);

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
        auto expr = sema.SemaVarAccessNode(current.context);
        Advance();
        return expr;
    }
    else
    {
        auto factor = sema.SemaNumberNode(current.value, current.ty);
        Advance();
        return factor;
    }
}

std::shared_ptr<AstNode> Parser::ParseExpr()
{
    bool isAssignExpr = false;
    lexer.SaveState();
    if(current.tokenType == TokenType::identifier) {
        Token next;
        lexer.NextToken(next);
        if(next.tokenType == TokenType::equal)
            isAssignExpr = true;
    }
    lexer.RestoreState();
    if(isAssignExpr)
        return ParseAssignExpr();

    auto left = ParseTerm();
    while (current.tokenType == TokenType::minus || current.tokenType == TokenType::plus)
    {
        Opcode op;
        if (current.tokenType == TokenType::plus)
            op = Opcode::add;
        else
            op = Opcode::sub;
        Advance();
        auto right = ParseTerm();;
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
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
        auto right = ParseFactor();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseAssignExpr()
{
    Expect(TokenType::identifier);
    auto text = current.context;
    Advance();
    auto expr = sema.SemaVarAccessNode(text);
    Consume(TokenType::equal);
    return sema.SemaAssignExprNode(expr, ParseExpr());
}

std::shared_ptr<Program> Parser::ParseProgram()
{
    std::vector<std::shared_ptr<AstNode>> astVec;
    while (current.tokenType != TokenType::eof)
    {
        if (current.tokenType == TokenType::semi)
        {
            Advance();
            continue;
        }
        if (current.tokenType == TokenType::kw_int)
        {
            const auto &decls = PasreDeclStmt();
            for (auto &decl : decls)
                astVec.push_back(decl);
        }
        else
        {
            auto expr = ParseExprStmt();
            astVec.push_back(expr);
        }
    }
    auto program = std::make_shared<Program>();
    program->astNodes = std::move(astVec);
    return program;
}

std::shared_ptr<AstNode> Parser::ParseExprStmt() {
    auto expr = ParseExpr();
    Consume(TokenType::semi);
    return expr;
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
