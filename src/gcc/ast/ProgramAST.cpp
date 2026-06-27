#include "gcc/ast/ProgramAST.hpp"

#include "gcc/ast/Statement.hpp"

ProgramAST::ProgramAST(std::unique_ptr<Statement>  function):function(std::move(function)) {

}
