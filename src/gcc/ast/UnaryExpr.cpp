#include "gcc/ast/UnaryExpr.hpp"

#include "gcc/ast/Expression.hpp"
#include "gcc/lexer/Token.hpp"

UnaryExpr::UnaryExpr(const Token &operatr, std::unique_ptr<Expression> expression): operator_(operatr), expression_(std::move(expression)) {

}

void UnaryExpr::accept(Visitor &v) {
    v.visit(*this);
}

Token UnaryExpr::getOperator() const {
    return operator_;
}

Expression& UnaryExpr::getExpression() const {
    return *expression_;
}
