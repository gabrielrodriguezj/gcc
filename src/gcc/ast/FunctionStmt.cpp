#include "gcc/ast/FunctionStmt.hpp"

#include "gcc/ast/Statement.hpp"

FunctionStmt::FunctionStmt(Token &name, Statement &body) : name(name), body(body) {

}
