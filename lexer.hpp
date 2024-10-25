#pragma once
#include "type.hpp"
#include "llvm/Support/StringSaver.h"
#include "llvm/IR/Module.h"
#include "diag_engine.hpp"

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
    int row, col;
    TokenType tokenType;
    int value;
    int len;
    CType *ty;
    const char* ptr;
    void Dump()
    {
        llvm::outs() << "{" << llvm::StringRef(ptr, len) << ", row = " << row << ", col = " << col << "}\n";
    }
    static llvm::StringRef GetSpellingText(TokenType tokenType);
};

class Lexer
{
public:
    Lexer(llvm::SourceMgr& mgr, DiagEngine& DiagEngine);
    void NextToken(Token &token);
    void SaveState();
    void RestoreState();

    DiagEngine& GetDiagEngine() const {
        return diagEngine;
    }
private:
    llvm::SourceMgr &mgr;
    DiagEngine& diagEngine;
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