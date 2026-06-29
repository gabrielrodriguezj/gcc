#include "gcc/ast/ConstantExpr.hpp"

#include "gcc/lexer/Token.hpp"

ConstantExpr :: ConstantExpr(const Token &constantValue) : value(constantValue) {
}

void ConstantExpr::accept(Visitor &v) {
    v.visit(*this);
}

Token ConstantExpr::getValue() {
    return value;
}
