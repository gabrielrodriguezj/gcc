#ifndef GCC_PARSERPASS_HPP
#define GCC_PARSERPASS_HPP
#include "Pass.hpp"
#include "gcc/driver/CompilerContext.hpp"

class ParserPass : public Pass
{
public:
    void run(CompilerContext&) override;
};

#endif //GCC_PARSERPASS_HPP
