#pragma once
#include <memory>
#include "lexer.hpp"
#include "ast.hpp"
class Parser {
    Token current;
    Lexer lexer;
    std::shared_ptr<Expr> ParseFactor(); 
    std::shared_ptr<Expr> ParseExpr(); 
    std::shared_ptr<Expr> ParseTerm(); 
    public:
    Parser(Lexer& lexer) : lexer(lexer) {
        Advance();
    }
    std::shared_ptr<Program> ParseProgram();
    bool Expect(TokenType tokenType);
    bool Consume(TokenType tokenType);
    void Advance();

};