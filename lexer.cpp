#include "lexer.hpp"
#include <cctype>
#include "type.hpp"
#include "diag_engine.hpp"

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

Lexer::Lexer(llvm::SourceMgr &mgr, DiagEngine &diagEngine) : mgr(mgr), diagEngine(diagEngine)
{
    unsigned id = mgr.getMainFileID();
    llvm::StringRef buf = mgr.getMemoryBuffer(id)->getBuffer();
    BufPtr = buf.begin();
    LineHeadPtr = BufPtr;
    BufEnd = buf.end();
    row = 1;
}

void Lexer::NextToken(Token &token)
{

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

    token.row = row;
    token.col = BufPtr - LineHeadPtr + 1;

    const char *startPtr = BufPtr;
    if (IsDigit(*BufPtr))
    {
        int number = 0;
        do
        {
            number = number * 10 + *BufPtr - '0';
            BufPtr++;
        } while (IsDigit(*BufPtr));
        token.tokenType = TokenType::number;
        token.ptr = startPtr;
        token.len = BufPtr - startPtr;
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
        token.ptr = startPtr;
        token.len = BufPtr - startPtr;
        auto text = llvm::StringRef(token.ptr, token.len);
        if (text == "int")
            token.tokenType = TokenType::kw_int;
        else if(text == "if") 
            token.tokenType = TokenType::kw_if;
        else if(text == "else") 
            token.tokenType = TokenType::kw_else;
    }
    else
    {
        token.ptr = startPtr;
        token.len = 1;
        switch (*BufPtr)
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
        case '{':
            token.tokenType = TokenType::l_brace;
            break;
        case '}':
            token.tokenType = TokenType::r_brace;
            break;
        default:
            diagEngine.Report(llvm::SMLoc::getFromPointer(BufPtr), diag::err_unknown_char, *BufPtr);
            break;
        }
        BufPtr++;
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

llvm::StringRef Token::GetSpellingText(TokenType tokenType)
{
    switch (tokenType)
    {
    case TokenType::kw_int:
        return "int";
    case TokenType::minus:
        return "-";
    case TokenType::plus:
        return "+";
    case TokenType::star:
        return "*";
    case TokenType::slash:
        return "/";
    case TokenType::l_parent:
        return "(";
    case TokenType::r_parent:
        return ")";
    case TokenType::semi:
        return ";";
    case TokenType::equal:
        return "=";
    case TokenType::comma:
        return ",";
    case TokenType::identifier:
        return "identifier";
    case TokenType::number:
        return "number";
    default:
        llvm::llvm_unreachable_internal();
    }
}
