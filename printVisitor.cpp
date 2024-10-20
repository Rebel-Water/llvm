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
    default:
        break;
    }

    binaryExpr->right->Accept(this);

    return nullptr;
}

llvm::Value *PrintVisitor::VisitNumberExpr(NumberExpr *numberExpr)
{
    llvm::outs() << numberExpr->value;
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
    if(decl->ty == CType::GetIntTy())
        llvm::outs() << "int " << decl->name << ";";
    return nullptr;
}
llvm::Value * PrintVisitor::VisitVariableAccessExpr(VariableAccessExpr *expr)
{
    llvm::outs() << expr->name;
    return nullptr;
}