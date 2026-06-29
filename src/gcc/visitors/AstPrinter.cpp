#include "gcc/visitors/AstPrinter.hpp"

#include "gcc/ast/ConstantExpr.hpp"
#include "gcc/ast/FunctionStmt.hpp"
#include "gcc/ast/ProgramAST.hpp"
#include "gcc/ast/ReturnStmt.hpp"

AstPrinter::AstPrinter(std::ostream& out, const SourceManager& sourceManager): out(out), sourceManager(sourceManager) {

}

void AstPrinter::visit(ConstantExpr& expr) {
    out << std::string(indent - 1, '\t') << "|--- Constant" << std::endl;
    out << std::string(indent - 1, '\t') << "     value: " << sourceManager.lexeme(expr.getValue()) << std::endl;
}

void AstPrinter::visit(FunctionStmt& stmt) {
    out << std::string(indent - 1, '\t') << "|--- Function" << std::endl;
    out << std::string(indent - 1, '\t') << "     name: " << sourceManager.lexeme(stmt.getToken()) << std::endl;
    out << std::string(indent - 1, '\t') << "     body: " << std::endl;
    indent++;
    stmt.getBody().accept(*this);
    indent--;
}

void AstPrinter::visit(ReturnStmt& stmt) {
    out << std::string(indent - 1, '\t') << "|--- Return" << std::endl;
    out << std::string(indent - 1, '\t') << "     Expression: " << std::endl;
    indent++;
    stmt.getExpression().accept(*this);
    indent--;
}

void AstPrinter::visit(ProgramAST& stmt) {
    out << "Program: " << std::endl;
    indent++;
    stmt.getFunction().accept(*this);
    indent--;
}