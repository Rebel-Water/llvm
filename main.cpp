#include "lexer.hpp"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/ErrorOr.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if(argc < 2) {
        std::cerr << "plz input filename!\n";
        return -1;
    }
    const char* file_name = argv[1];
    static llvm::ErrorOr<std::unique_ptr<llvm::MemoryBuffer>> buf = llvm::MemoryBuffer::getFile(file_name); 
    if(!buf) {
        llvm::errs() << "can't open file!";
        return -1;
    }
    auto memBuf = std::move(*buf);
    Lexer lex(memBuf->getBuffer());
    Token token;
    while(true) {
        lex.NextToken(token);
        if(token.tokenType == TokenType::eof)
            break;
        token.Dump();
    }
    return 0;
}