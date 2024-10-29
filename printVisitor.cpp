#include "printVisitor.hpp"

PrintVisitor::PrintVisitor(std::shared_ptr<Program> program)
{
    VisitProgram(program.get());
}

llvm::Value *PrintVisitor::VisitProgram(Program *p)
{
    for (auto &node : p->astNodes)
    {
        node->Accept(this);
        llvm::outs() << "\n";
    }
    return nullptr;
}

llvm::Value *PrintVisitor::VisitBinaryExpr(BinaryExpr *binaryExpr)
{
    binaryExpr->left->Accept(this);

    switch (binaryExpr->opcode)
    {
    case Opcode::add:
        llvm::outs() << " + ";
        break;
    case Opcode::sub:
        llvm::outs() << " - ";
        break;
    case Opcode::mul:
        llvm::outs() << " * ";
        break;
    case Opcode::div:
        llvm::outs() << " / ";
        break;
    case Opcode::less:
        llvm::outs() << " < ";
        break;
    case Opcode::greater:
        llvm::outs() << " > ";
        break;
    case Opcode::less_equal:
        llvm::outs() << " <= ";
        break;
    case Opcode::greater_equal:
        llvm::outs() << " >= ";
        break;
    case Opcode::equal_equal:
        llvm::outs() << " == ";
        break;
    case Opcode::not_equal:
        llvm::outs() << " != ";
        break;
    default:
        break;
    }

    binaryExpr->right->Accept(this);

    return nullptr;
}

llvm::Value *PrintVisitor::VisitNumberExpr(NumberExpr *numberExpr)
{
    llvm::outs() << numberExpr->token.value;
    return nullptr;
}

llvm::Value *PrintVisitor::VisitAssignExpr(AssignExpr *expr)
{
    expr->left->Accept(this);
    llvm::outs() << " = ";
    expr->right->Accept(this);
    return nullptr;
}
llvm::Value *PrintVisitor::VisitVariableDecl(VariableDecl *decl)
{
    if (decl->ty == CType::GetIntTy())
    {
        llvm::StringRef text(decl->token.ptr, decl->token.len);
        llvm::outs() << "int " << text << ";";
    }
    return nullptr;
}
llvm::Value *PrintVisitor::VisitVariableAccessExpr(VariableAccessExpr *expr)
{
    llvm::StringRef text(expr->token.ptr, expr->token.len);
    llvm::outs() << text;
    return nullptr;
}

llvm::Value *PrintVisitor::VisitIfStmt(IfStmt *stmt)
{
    llvm::outs() << "if (";
    stmt->condNode->Accept(this);
    llvm::outs() << ")";
    stmt->thenNode->Accept(this);
    if (stmt->elseNode)
    {
        llvm::outs() << "\nelse\n";
        stmt->elseNode->Accept(this);
    }
    return nullptr;
}

llvm::Value *PrintVisitor::VisitDeclStmt(DeclStmt *stmt)
{
    for (auto &node : stmt->astVec)
        node->Accept(this);
    return nullptr;
}

llvm::Value *PrintVisitor::VisitBlockStmt(BlockStmt *stmt)
{
    llvm::outs() << "{\n";
    for(const auto& stmt : stmt->astVec) {
        stmt->Accept(this);
        llvm::outs() << "\n";
    }
    llvm::outs() << "}\n";
    return nullptr;
}
