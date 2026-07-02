#ifndef GCC_EXPRESSION_HPP
#define GCC_EXPRESSION_HPP

#include <memory>

#include "gcc/lexer/Token.hpp"
#include "gcc/visitors/Visitor.hpp"

class Expression {
public:
    virtual ~Expression() = default;
    virtual void accept(Visitor& visitor) = 0;
};

#endif //GCC_EXPRESSION_HPP
