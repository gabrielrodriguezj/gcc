#include "gcc/ast/ReturnStmt.hpp"

ReturnStmt :: ReturnStmt(std::unique_ptr<Expression>  expression) :
    expression_(std::move(expression)) {}

void ReturnStmt :: accept(Visitor &visitor) {
    visitor.visit(*this);
}

Expression& ReturnStmt::getExpression() const {
    return *expression_;
}
