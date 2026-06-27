#ifndef GCC_STATEMENT_HPP
#define GCC_STATEMENT_HPP

#include <memory>

#include "gcc/lexer/Token.hpp"
#include "gcc/visitors/Visitor.hpp"

class Statement {
public:
    virtual void accept(Visitor& visitor) = 0;
};

#endif //GCC_STATEMENT_HPP
