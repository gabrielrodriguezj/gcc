#ifndef GCC_UNARYEXPR_HPP
#define GCC_UNARYEXPR_HPP
#include "Expression.hpp"

class UnaryExpr : public Expression {

public:
    UnaryExpr(const Token &, std::unique_ptr<Expression>);
    void accept(Visitor&) override;

    Token getOperator() const;
    Expression& getExpression() const;

private:
    Token operator_;
    std::unique_ptr<Expression> expression_;
};

#endif //GCC_UNARYEXPR_HPP
