#pragma once
#include <memory>
#include "lexer.hpp"
#include "ast.hpp"
#include "sema.hpp"
class Parser {
    Token current;
    Lexer& lexer;
    Sema& sema;

    std::vector<std::shared_ptr<AstNode>> PasreDeclStmt();
    std::shared_ptr<AstNode> ParseExprStmt();
    std::shared_ptr<AstNode> ParseFactor(); 
    std::shared_ptr<AstNode> ParseExpr(); 
    std::shared_ptr<AstNode> ParseTerm(); 
    std::shared_ptr<AstNode> ParseAssignExpr(); 
    public:
    Parser(Lexer& lexer, Sema& sema) : lexer(lexer) , sema(sema) {
        Advance();
    }
    std::shared_ptr<Program> ParseProgram();
    bool Expect(TokenType tokenType);
    bool Consume(TokenType tokenType);
    void Advance();

};