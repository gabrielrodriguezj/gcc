#include "gcc/ast/FunctionStmt.hpp"

#include "gcc/ast/Statement.hpp"

FunctionStmt::FunctionStmt(Token &name, std::unique_ptr<Statement> body) : name(name), body(std::move(body)) {

}
