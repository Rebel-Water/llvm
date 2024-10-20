#include "scope.hpp"

Scope::Scope()
{
    envs.push_back(std::make_shared<Env>());
}

void Scope::EnterScope()
{
    envs.push_back(std::make_shared<Env>());
}

void Scope::ExitScope()
{
    envs.pop_back();
}

std::shared_ptr<Symbol> Scope::FindVarSymbol(llvm::StringRef name)
{
    auto it = std::find_if(envs.rbegin(), envs.rend(), [&](const auto &env)
                           {
        auto& table = env->varSymbolTable;
        return table.count(name) > 0; }
    );

    if (it != envs.rend())
        return (*it)->varSymbolTable[name];

    return nullptr;
}

std::shared_ptr<Symbol> Scope::FindVarSymbolInCurEnv(llvm::StringRef name)
{
    auto &table = envs.back()->varSymbolTable;
    if (table.count(name) > 0)
        return table[name];
    return nullptr;
}

void Scope::AddSymbol(SymbolKind kind, CType *ty, llvm::StringRef name)
{
    auto symbol = std::make_shared<Symbol>(kind, ty, name);
    envs.back()->varSymbolTable.insert({name, symbol}); // why not insert or assign
}
