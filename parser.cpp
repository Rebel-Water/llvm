#include "parser.hpp"
#include <cassert>
#include <mutex>

std::shared_ptr<AstNode> Parser::ParseDeclStmt()
{
    Consume(TokenType::kw_int);
    CType *baseTy = CType::GetIntTy();
    auto decl = std::make_shared<DeclStmt>();

    while (current.tokenType != TokenType::semi)
    {
        Token temp = current;
        auto variableDecl = sema.SemaVarDeclNode(temp, baseTy);
        decl->astVec.push_back(variableDecl);
        Consume(TokenType::identifier);

        // int a = 1, b = 2; => int a; a = 1; int b; b = 2;
        if (current.tokenType == TokenType::equal)
        {
            Advance();
            auto left = sema.SemaVarAccessNode(temp);
            auto right = ParseExpr();
            auto assignExpr = sema.SemaAssignExprNode(left, right, temp);

            decl->astVec.push_back(assignExpr);
        }
        if (Peek(TokenType::comma))
            Advance();
    }
    Expect(TokenType::semi);
    return decl;
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
        auto expr = sema.SemaVarAccessNode(current);
        Advance();
        return expr;
    }
    else
    {
        Expect(TokenType::number);
        auto factor = sema.SemaNumberNode(current, current.ty);
        Advance();
        return factor;
    }
}

std::shared_ptr<AstNode> Parser::ParseIfStmt()
{
    Consume(TokenType::kw_if);
    Consume(TokenType::l_parent);
    auto condExpr = ParseExpr();
    Consume(TokenType::r_parent);
    auto thenStmt = ParseStmt();
    std::shared_ptr<AstNode> elseStmt = nullptr;
    if(current.tokenType == TokenType::kw_else) {
        Consume(TokenType::kw_else);
        elseStmt = ParseStmt();
    }
    return sema.SemaIfStmtNode(condExpr, thenStmt, elseStmt);
}

std::shared_ptr<AstNode> Parser::ParseBlockStmt()
{
    sema.scope.EnterScope();
    Consume(TokenType::l_brace);

    auto blockstmt = std::make_shared<BlockStmt>();

    while(current.tokenType != TokenType::r_brace) {
        auto stmt = ParseStmt();
        blockstmt->astVec.push_back(stmt);
    }

    Consume(TokenType::r_brace);
    sema.scope.ExitScope();

    return blockstmt;
}

std::shared_ptr<AstNode> Parser::ParseStmt()
{
    if (current.tokenType == TokenType::semi)
    {
        Advance();
        return nullptr;
    }
    else if (current.tokenType == TokenType::kw_int)
    {
        return ParseDeclStmt();
    }
    else if (current.tokenType == TokenType::kw_if)
    {
        return ParseIfStmt();
    }
    else if(current.tokenType == TokenType::l_brace) {
        return ParseBlockStmt();
    }
    else
    {
        return ParseExprStmt();
    }
    return nullptr; 
}

std::shared_ptr<AstNode> Parser::ParseExpr()
{
    bool isAssignExpr = false;
    lexer.SaveState();
    if (current.tokenType == TokenType::identifier) // substitue for peekToken
    {
        Token next;
        lexer.NextToken(next);
        if (next.tokenType == TokenType::equal)
            isAssignExpr = true;
    }
    lexer.RestoreState();
    if (isAssignExpr)
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
        auto right = ParseTerm();
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
    auto temp = current;
    Advance();
    auto expr = sema.SemaVarAccessNode(temp);
    temp = current;
    Consume(TokenType::equal);
    return sema.SemaAssignExprNode(expr, ParseExpr(), temp);
}

std::shared_ptr<Program> Parser::ParseProgram()
{
    std::vector<std::shared_ptr<AstNode>> astVec;
    while (current.tokenType != TokenType::eof)
    {
        auto stmt = ParseStmt();
        if (stmt)
            astVec.push_back(stmt);
    }
    auto program = std::make_shared<Program>();
    program->astNodes = std::move(astVec);
    return program;
}

std::shared_ptr<AstNode> Parser::ParseExprStmt()
{
    auto expr = ParseExpr();
    Consume(TokenType::semi);
    return expr;
}

bool Parser::Expect(TokenType tokenType)
{
    if (current.tokenType == tokenType)
        return true;
    Error(tokenType);
    return false;
}

void Parser::Advance()
{
    lexer.NextToken(current);
}

bool Parser::Consume(TokenType tokenType)
{
    if (Expect(tokenType))
    {
        Advance();
        return true;
    }
    return false;
}

bool Parser::Peek(TokenType tokenType)
{
    return current.tokenType == tokenType;
}

void Parser::Error(TokenType tokenType)
{
    GetDiagEngine().Report(llvm::SMLoc::getFromPointer(current.ptr),
                           diag::err_expected,
                           Token::GetSpellingText(tokenType),
                           llvm::StringRef(current.ptr, current.len));
}
