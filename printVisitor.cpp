#include "printVisitor.hpp"

PrintVisitor::PrintVisitor(std::shared_ptr<Program> program)
{
    VisitrProgram(program.get());
}

void PrintVisitor::VisitrProgram(Program *p)
{
    for(auto& expr : p->exprVec) {
        expr->Accept(this);
        llvm::outs() << "\n";
    }
}

void PrintVisitor::VisitBinaryExpr(BinaryExpr *binaryExpr)
{
    binaryExpr->left->Accept(this);
    binaryExpr->right->Accept(this);
    switch (binaryExpr->opcode)
    {
    case Opcode::add:
        llvm::outs() << " +";
        break;
    case Opcode::sub:
        llvm::outs() << " -";
        break;
    case Opcode::mul:
        llvm::outs() << " *";
        break;
    case Opcode::div:
        llvm::outs() << " /";
        break;
    default:
        break;
    }
}

void PrintVisitor::VisitFactorExpr(FactorExpr *factorExpr)
{
    llvm::outs() << factorExpr->value;
}
