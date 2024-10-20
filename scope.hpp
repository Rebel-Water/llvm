#pragma once
#include <vector>
#include <memory>
#include "type.hpp"
#include "llvm/ADT/StringMap.h"

enum class SymbolKind {
    LocalVariable
};

struct Symbol {
    SymbolKind kind;
    CType* ty;
    llvm::StringRef name;
    Symbol(SymbolKind kind, CType* ty, llvm::StringRef name) : kind(kind), ty(ty), name(name) {}
};

struct Env {
    llvm::StringMap<std::shared_ptr<Symbol>> varSymbolTable;
};

class Scope {
    std::vector<std::shared_ptr<Env>> envs;
    public:
    Scope();
    void EnterScope();
    void ExitScope();
    std::shared_ptr<Symbol> FindVarSymbol(llvm::StringRef name);
    std::shared_ptr<Symbol> FindVarSymbolInCurEnv(llvm::StringRef name);
    void AddSymbol(SymbolKind kind, CType* ty, llvm::StringRef name);
};