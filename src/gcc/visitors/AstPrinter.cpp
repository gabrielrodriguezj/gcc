#include "gcc/visitors/AstPrinter.hpp"

void AstPrinter::visit(ConstantExpr& expr) {
    out << "testing: ConstantExpr node" << std::endl;
}

void AstPrinter::visit(FunctionStmt& stmt) {
    out << "testing: FunctionStmt node" << std::endl;
}

void AstPrinter::visit(ReturnStmt& stmt) {
    out << "testing: ReturnStmt node" << std::endl;
}

void AstPrinter::visit(ProgramAST& stmt) {
    out << "testing: ProgramAST node" << std::endl;
}