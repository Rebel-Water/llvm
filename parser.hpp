#pragma once
#include <memory>
#include "lexer.hpp"
#include "ast.hpp"
class Parser {
    Token current;
    Lexer lexer;
    std::vector<std::shared_ptr<AstNode>> PasreDecl();
    std::shared_ptr<AstNode> ParseFactor(); 
    std::shared_ptr<AstNode> ParseExpr(); 
    std::shared_ptr<AstNode> ParseTerm(); 
    public:
    Parser(Lexer& lexer) : lexer(lexer) {
        Advance();
    }
    std::shared_ptr<Program> ParseProgram();
    bool Expect(TokenType tokenType);
    bool Consume(TokenType tokenType);
    void Advance();

};