#include "gcc/ast/ProgramAST.hpp"

#include <functional>

#include "gcc/ast/FunctionStmt.hpp"
#include "gcc/ast/Statement.hpp"

ProgramAST::ProgramAST(std::unique_ptr<Statement>  function):function(std::move(function)) {

}

void ProgramAST::accept(Visitor &visitor) {
    visitor.visit(*this);
}

Statement& ProgramAST::getFunction() {
    return *this->function;
}
