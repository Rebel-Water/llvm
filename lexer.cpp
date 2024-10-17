#include "lexer.hpp"
#include <cctype>

static bool IsWhiteSpace(char ch)
{
    return std::isspace(ch);
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
    if (std::isdigit(*BufPtr))
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
        token.value = number;
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
        default:
            token.tokenType = TokenType::unknow;
            break;
        }
    }
}
