#include "gcc/visitors/AstPrinter.hpp"

#include "gcc/ast/ConstantExpr.hpp"
#include "gcc/ast/FunctionStmt.hpp"
#include "gcc/ast/ProgramAST.hpp"
#include "gcc/ast/ReturnStmt.hpp"

AstPrinter::AstPrinter(std::ostream& out, const SourceManager& sourceManager): out_(out), sourceManager_(sourceManager) {

}

void AstPrinter::print(ProgramAST &stmt) {
    stmt.accept(*this);
}

void AstPrinter::visit(ConstantExpr& expr) {
    out_ << std::string(indent_ - 1, '\t') << "|--- Constant" << std::endl;
    out_ << std::string(indent_ - 1, '\t') << "     value: " << sourceManager_.lexeme(expr.getValue()) << std::endl;
}

void AstPrinter::visit(FunctionStmt& stmt) {
    out_ << std::string(indent_ - 1, '\t') << "|--- Function" << std::endl;
    out_ << std::string(indent_ - 1, '\t') << "     name: " << sourceManager_.lexeme(stmt.getName()) << std::endl;
    out_ << std::string(indent_ - 1, '\t') << "     body: " << std::endl;
    indent_++;
    stmt.getBody().accept(*this);
    indent_--;
}

void AstPrinter::visit(ReturnStmt& stmt) {
    out_ << std::string(indent_ - 1, '\t') << "|--- Return" << std::endl;
    out_ << std::string(indent_ - 1, '\t') << "     Expression: " << std::endl;
    indent_++;
    stmt.getExpression().accept(*this);
    indent_--;
}

void AstPrinter::visit(ProgramAST& stmt) {
    out_ << "Program: " << std::endl;
    indent_++;
    stmt.getFunction().accept(*this);
    indent_--;
}