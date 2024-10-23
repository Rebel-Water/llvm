#pragma once
#include "type.hpp"
#include "llvm/Support/StringSaver.h"
#include "llvm/IR/Module.h"

#define TOKENNAME \
    X(unknow)     \
    X(number)     \
    X(identifier) \
    X(kw_int)     \
    X(minus)      \
    X(plus)       \
    X(star)       \
    X(slash)      \
    X(l_parent)   \
    X(r_parent)   \
    X(semi)       \
    X(equal)      \
    X(comma)      \
    X(eof)

enum class TokenType
{
#define X(NAME) NAME,
    TOKENNAME
#undef X
};

llvm::raw_ostream &operator<<(llvm::raw_ostream &os, const TokenType &tokenType);

struct Token
{
    Token() : row(-1), col(-1), tokenType(TokenType::unknow), value(-1) {}
    int row, col;
    TokenType tokenType;
    int value;
    CType *ty;
    llvm::StringRef context;
    void Dump()
    {
        llvm::outs() << "{ row: " << row << ", " << "col: " << col << ", " << "type: " << tokenType << ", "
                     << "context: " << context << "}\n";
    }
};

class Lexer
{
public:
    Lexer(llvm::StringRef src);
    void NextToken(Token &token);
    void SaveState();
    void RestoreState();

private:
    const char *BufPtr;
    const char *LineHeadPtr;
    const char *BufEnd;
    int row = 1;
    struct State
    {
        const char *BufPtr;
        const char *LineHeadPtr;
        const char *BufEnd;
        int row;
    };
    State state;
};