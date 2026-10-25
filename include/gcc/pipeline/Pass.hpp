#ifndef GCC_PASS_HPP
#define GCC_PASS_HPP
#include "../core/CompilerContext.hpp"

class Pass {
public:
    virtual ~Pass() = default;

    virtual void run(CompilerContext&) = 0;
};

#endif //GCC_PASS_HPP
