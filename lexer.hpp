#pragma once
#include "llvm/Support/StringSaver.h"
#include "llvm/IR/Module.h"

enum class TokenType {
    unknow,
    number, // ([0-9]+)
    minus,
    plus,
    star,
    slash,
    l_parent, // {
    r_parent, // }
    semi, // ;
    eof,
};

struct Token {
    Token() : row(-1), col(-1), tokenType(TokenType::unknow), value(-1) {}
    int row, col;
    TokenType tokenType;
    int value;
    llvm::StringRef context;
    void Dump() {
        llvm::outs() << "{ row: " << row << ", " << "col: " << col << ", context: " << context << "}\n";
    }
};

class Lexer {
public:
    Lexer(llvm::StringRef src);
    void NextToken(Token& token);
private:
    const char* BufPtr;
    const char* LineHeadPtr;
    const char* BufEnd;
    int row = 1;
};