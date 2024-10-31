#pragma once
#include "type.hpp"
#include "llvm/Support/StringSaver.h"
#include "llvm/IR/Module.h"
#include "diag_engine.hpp"

#define TOKENNAME      \
    X(unknow)          \
    X(number)          \
    X(identifier)      \
    X(kw_int)          \
    X(kw_if)           \
    X(kw_else)         \
    X(kw_continue)     \
    X(kw_break)        \
    X(kw_for)          \
    X(minus)           \
    X(plus)            \
    X(star)            \
    X(slash)           \
    X(l_parent)        \
    X(r_parent)        \
    X(l_brace)         \
    X(r_brace)         \
    X(semi)            \
    X(equal)           \
    X(comma)           \
    X(equal_equal)     \
    X(not_equal)       \
    X(less)            \
    X(less_less)       \
    X(greater)         \
    X(greater_greater) \
    X(greater_equal)   \
    X(less_equal)      \
    X(not_)            \
    X(pipe)            \
    X(pipepipe)        \
    X(amp)             \
    X(ampamp)          \
    X(percent)         \
    X(caret)         \
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
    Token() = default;
    Token(TokenType tokenType, int row, int col) : tokenType(tokenType), row(row), col(col) {}
    int row, col;
    TokenType tokenType;
    int value;
    int len;
    CType *ty;
    const char *ptr;
    void Dump()
    {
        llvm::outs() << "{" << llvm::StringRef(ptr, len) << ", row = " << row << ", col = " << col << "}\n";
    }
    static llvm::StringRef GetSpellingText(TokenType tokenType);
};

class Lexer
{
public:
    Lexer(llvm::SourceMgr &mgr, DiagEngine &DiagEngine);
    void NextToken(Token &token);
    void SaveState();
    void RestoreState();

    DiagEngine &GetDiagEngine() const
    {
        return diagEngine;
    }

private:
    llvm::SourceMgr &mgr;
    DiagEngine &diagEngine;
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