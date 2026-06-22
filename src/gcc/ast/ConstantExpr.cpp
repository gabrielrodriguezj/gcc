#include "gcc/ast/ConstantExpr.hpp"

#include "gcc/lexer/Token.hpp"

ConstantExpr :: ConstantExpr(const Token &constantValue) : value(constantValue) {
}
