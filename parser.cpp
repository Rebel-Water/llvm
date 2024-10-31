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
    Consume(TokenType::semi);
    return decl;
}

std::shared_ptr<AstNode> Parser::ParsePrimary()
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

std::shared_ptr<AstNode> Parser::ParseLogOrExpr() {
    auto left = ParseLogAndExpr();
    while (current.tokenType == TokenType::pipepipe) {
        Opcode op = Opcode::logOr;
        Advance();
        auto right = ParseLogAndExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseLogAndExpr()
{
    auto left = ParseBitOrExpr();
    while (current.tokenType == TokenType::ampamp) {
        Opcode op = Opcode::logAnd;
        Advance();
        auto right = ParseBitOrExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseBitOrExpr()
{
    auto left = ParseBitXorExpr();
    while (current.tokenType == TokenType::pipe) {
        Opcode op = Opcode::bitOr;
        Advance();
        auto right = ParseBitXorExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseBitXorExpr()
{
    auto left = ParseBitAndExpr();
    while (current.tokenType == TokenType::caret) {
        Opcode op = Opcode::bitXor;
        Advance();
        auto right = ParseBitAndExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseBitAndExpr()
{
    auto left = ParseEqualExpr();
    while (current.tokenType == TokenType::amp) {
        Opcode op = Opcode::bitAnd;
        Advance();
        auto right = ParseEqualExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseShiftExpr()
{
    auto left = ParseAddExpr();
    while (current.tokenType == TokenType::less_less || current.tokenType == TokenType::greater_greater) {
        Opcode op = Opcode::leftShift;
        if(current.tokenType == TokenType::greater_greater)
            op = Opcode::rightShift;
        Advance();
        auto right = ParseAddExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseRelationalExpr()
{
    auto left = ParseShiftExpr();
    while (current.tokenType == TokenType::less || current.tokenType == TokenType::less_equal || current.tokenType == TokenType::greater_equal || current.tokenType == TokenType::greater)
    {
        Opcode op;
        if (current.tokenType == TokenType::less)
            op = Opcode::less;
        else if (current.tokenType == TokenType::greater)
            op = Opcode::greater;
        else if (current.tokenType == TokenType::less_equal)
            op = Opcode::less_equal;
        else 
            op = Opcode::greater_equal;
        Advance();
        auto right = ParseShiftExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseIfStmt()
{
    Consume(TokenType::kw_if);
    Consume(TokenType::l_parent);
    auto condExpr = ParseExpr();
    Consume(TokenType::r_parent);
    auto thenStmt = ParseStmt();
    std::shared_ptr<AstNode> elseStmt = nullptr;
    if (current.tokenType == TokenType::kw_else)
    {
        Consume(TokenType::kw_else);
        elseStmt = ParseStmt();
    }
    return sema.SemaIfStmtNode(condExpr, thenStmt, elseStmt);
}

std::shared_ptr<AstNode> Parser::ParseForStmt()
{
    Consume(TokenType::kw_for);
    Consume(TokenType::l_parent);

    std::shared_ptr<ForStmt> node = std::make_shared<ForStmt>();
    breakNodes.push_back(node);
    continueNodes.push_back(node);

    std::shared_ptr<AstNode> cond;
    std::shared_ptr<AstNode> body;
    std::shared_ptr<AstNode> inc;
    std::shared_ptr<AstNode> init;

    sema.scope.EnterScope();

    if(IsTypeName()) {
        init = ParseDeclStmt();
    } else {
        if(current.tokenType != TokenType::semi)
            init = ParseExpr();
        Consume(TokenType::semi);
    }

    if(current.tokenType != TokenType::semi)
        cond = ParseExpr();
    Consume(TokenType::semi);

    if(current.tokenType != TokenType::r_parent)
        inc = ParseExpr();
    Consume(TokenType::r_parent);

    body = ParseStmt();

    node->init = init;
    node->cond = cond;
    node->inc = inc;
    node->body = body;

    breakNodes.pop_back();
    continueNodes.pop_back();

    sema.scope.ExitScope();
    return node;
}

std::shared_ptr<AstNode> Parser::ParseBlockStmt()
{
    sema.scope.EnterScope();
    Consume(TokenType::l_brace);

    auto blockstmt = std::make_shared<BlockStmt>();

    while (current.tokenType != TokenType::r_brace)
    {
        auto stmt = ParseStmt();
        if(stmt)
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
    else if (IsTypeName())
    {
        return ParseDeclStmt();
    }
    else if (current.tokenType == TokenType::kw_if)
    {
        return ParseIfStmt();
    }
    else if (current.tokenType == TokenType::l_brace)
    {
        return ParseBlockStmt();
    }
    else if(current.tokenType == TokenType::kw_for) {
        return ParseForStmt();
    }
    else if(current.tokenType == TokenType::kw_continue) {
        return ParseContinueStmt();
    }
    else if(current.tokenType == TokenType::kw_break) {
        return ParseBreakStmt();
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

    auto ret = ParseLogOrExpr();
    return ret;
}

std::shared_ptr<AstNode> Parser::ParseEqualExpr()
{
    auto left = ParseRelationalExpr();
    while (current.tokenType == TokenType::equal_equal || current.tokenType == TokenType::not_equal)
    {
        Opcode op;
        if (current.tokenType == TokenType::equal_equal)
            op = Opcode::equal_equal;
        else
            op = Opcode::not_equal;
        Advance();
        auto right = ParseRelationalExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseAddExpr()
{
    auto left = ParseMultiExpr();
    while (current.tokenType == TokenType::minus || current.tokenType == TokenType::plus)
    {
        Opcode op;
        if (current.tokenType == TokenType::plus)
            op = Opcode::add;
        else
            op = Opcode::sub;
        Advance();
        auto right = ParseMultiExpr();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseMultiExpr()
{
    auto left = ParsePrimary();
    while (current.tokenType == TokenType::star || current.tokenType == TokenType::slash || current.tokenType == TokenType::percent)
    {
        Opcode op;
        if (current.tokenType == TokenType::star)
            op = Opcode::mul;
        else if(current.tokenType == TokenType::percent)
            op = Opcode::mod;
        else
            op = Opcode::div;
        Advance();
        auto right = ParsePrimary();
        auto binaryExpr = sema.SemaBinaryExprNode(left, right, op);
        left = binaryExpr;
    }
    return left;
}

std::shared_ptr<AstNode> Parser::ParseBreakStmt()
{
    if(breakNodes.empty())
        Error(current.tokenType);
    Consume(TokenType::kw_break);
    auto node = std::make_shared<BreakStmt>();
    node->target = breakNodes.back();
    Consume(TokenType::semi);
    return node;
}

std::shared_ptr<AstNode> Parser::ParseContinueStmt()
{
    if(continueNodes.empty())
        Error(current.tokenType);
    Consume(TokenType::kw_continue);
    auto node = std::make_shared<ContinueStmt>();
    node->target = continueNodes.back();
    Consume(TokenType::semi);
    return node;
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

bool Parser::IsTypeName()
{
    if(current.tokenType == TokenType::kw_int)
        return true;
    return false;
}

void Parser::Error(TokenType tokenType)
{
    GetDiagEngine().Report(llvm::SMLoc::getFromPointer(current.ptr),
                           diag::err_expected,
                           Token::GetSpellingText(tokenType),
                           llvm::StringRef(current.ptr, current.len));
}
