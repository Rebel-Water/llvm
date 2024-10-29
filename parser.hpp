#pragma once
#include <memory>
#include "lexer.hpp"
#include "ast.hpp"
#include "sema.hpp"
class Parser {
    Token current;
    Lexer& lexer;
    Sema& sema;

    std::shared_ptr<AstNode> ParseDeclStmt();
    std::shared_ptr<AstNode> ParseExprStmt();
    std::shared_ptr<AstNode> ParseStmt(); 
    std::shared_ptr<AstNode> ParseIfStmt(); 
    std::shared_ptr<AstNode> ParseBlockStmt(); 
    std::shared_ptr<AstNode> ParseExpr(); 
    std::shared_ptr<AstNode> ParseEqualExpr(); 
    std::shared_ptr<AstNode> ParseAddExpr(); 
    std::shared_ptr<AstNode> ParseMultiExpr(); 
    std::shared_ptr<AstNode> ParseAssignExpr(); 
    std::shared_ptr<AstNode> ParsePrimary(); 
    std::shared_ptr<AstNode> ParseRelationalExpr(); 
    public:
    Parser(Lexer& lexer, Sema& sema) : lexer(lexer) , sema(sema) {
        Advance();
    }
    std::shared_ptr<Program> ParseProgram();
    bool Expect(TokenType tokenType);
    bool Consume(TokenType tokenType);
    bool Peek(TokenType tokenType);
    void Error(TokenType tokenType);
    void Advance();

    DiagEngine& GetDiagEngine() {
        return lexer.GetDiagEngine();
    }
};