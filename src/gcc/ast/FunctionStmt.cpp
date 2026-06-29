#include "gcc/ast/FunctionStmt.hpp"

#include "gcc/ast/Statement.hpp"

FunctionStmt::FunctionStmt(Token &name, std::unique_ptr<Statement> body) :
    name(name), body(std::move(body)) {}

void FunctionStmt::accept(Visitor &visitor) {
    visitor.visit(*this);
}

Token FunctionStmt::getToken() const {
    return name;
}

Statement& FunctionStmt::getBody() const {
    return *body;
}
