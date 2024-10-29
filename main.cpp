#include <iostream>
#include "lexer.hpp"
#include "printVisitor.hpp"
#include "codegen.hpp"
#include "parser.hpp"
#include "ast.hpp"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/ErrorOr.h"
#include "sema.hpp"
#include "diag_engine.hpp"

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

    llvm::SourceMgr mgr;
    DiagEngine diag(mgr);
    mgr.AddNewSourceBuffer(std::move(*buf), llvm::SMLoc());

    Lexer lex(mgr, diag);

    // Token token; 
    // while(true) {
    //     lex.NextToken(token);
    //     if(token.tokenType == TokenType::eof)
    //         break;
    //     token.Dump();
    // }
    Sema sema(diag);

    Parser parser(lex, sema);
    auto program = parser.ParseProgram();
    Codegen codegen(program);
    // PrintVisitor print(program);
    
    return 0;
}