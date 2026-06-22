#ifndef GCC_CONSTANTEXPR_HPP
#define GCC_CONSTANTEXPR_HPP
#include "Expression.hpp"

class ConstantExpr : public Expression {

public:
    ConstantExpr(const Token &);

private:
    Token value;
};

#endif //GCC_CONSTANTEXPR_HPP
