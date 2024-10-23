#include "lexer.hpp"
#include <cctype>
#include "type.hpp"

static bool IsWhiteSpace(char ch)
{
    return std::isspace(ch);
}

static bool IsDigit(char ch)
{
    return std::isdigit(ch);
}

static bool IsLetter(char ch)
{
    return std::isalpha(ch);
}

Lexer::Lexer(llvm::StringRef src) : LineHeadPtr(src.begin()), BufPtr(src.begin()), BufEnd(src.end())
{
}

void Lexer::NextToken(Token &token)
{
    token.row = row;

    while (IsWhiteSpace(*BufPtr))
    {
        if (*BufPtr == '\n')
        {
            row++;
            LineHeadPtr = BufPtr + 1;
        }
        BufPtr++;
    }

    if (BufPtr >= BufEnd)
    {
        token.tokenType = TokenType::eof;
        return;
    }

    token.col = BufPtr - LineHeadPtr + 1;

    auto start = BufPtr;
    if (IsDigit(*BufPtr))
    {
        int number = 0;
        int size = 0;
        token.tokenType = TokenType::number;
        do
        {
            number += number * 10 + *BufPtr++ - '0';
            size++;
        } while (std::isdigit(*BufPtr));
        token.context = llvm::StringRef(start, size);
        token.ty = CType::GetIntTy();
        token.value = number;
    }
    else if (IsLetter(*BufPtr))
    {
        while (IsLetter(*BufPtr) || IsDigit(*BufPtr))
        {
            BufPtr++;
        }
        token.tokenType = TokenType::identifier;
        token.context = llvm::StringRef(start, BufPtr - start);
        if (token.context == "int")
        {
            token.tokenType = TokenType::kw_int;
        }
    }
    else
    {
        token.context = llvm::StringRef(start, 1);
        switch (*BufPtr++)
        {
        case '+':
            token.tokenType = TokenType::plus;
            break;
        case '-':
            token.tokenType = TokenType::minus;
            break;
        case '*':
            token.tokenType = TokenType::star;
            break;
        case '/':
            token.tokenType = TokenType::slash;
            break;
        case ';':
            token.tokenType = TokenType::semi;
            break;
        case '(':
            token.tokenType = TokenType::l_parent;
            break;
        case ')':
            token.tokenType = TokenType::r_parent;
            break;
        case ',':
            token.tokenType = TokenType::comma;
            break;
        case '=':
            token.tokenType = TokenType::equal;
            break;
        default:
            token.tokenType = TokenType::unknow;
            break;
        }
    }
}

void Lexer::SaveState()
{
    state.row = row;
    state.BufEnd = BufEnd;
    state.BufPtr = BufPtr;
    state.LineHeadPtr = LineHeadPtr;
}

void Lexer::RestoreState()
{
    row = state.row;
    BufEnd = state.BufEnd;
    BufPtr = state.BufPtr;
    LineHeadPtr = state.LineHeadPtr;
}

llvm::raw_ostream &operator<<(llvm::raw_ostream &os, const TokenType &tokenType)
{
    llvm::StringRef name = [&]()
    {
        switch (tokenType)
        {
#define X(name)           \
    case TokenType::name: \
        return #name;
            TOKENNAME
#undef X
        default: // cann't throw, we disable rtti
            return "No Such tokenType!";
        }
    }();
    os << name;
    return os;
}