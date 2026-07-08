#ifndef GCC_LEXERPASS_HPP
#define GCC_LEXERPASS_HPP
#include "Pass.hpp"
#include "gcc/driver/CompilerContext.hpp"
#include "gcc/lexer/Lexer.hpp"

class LexerPass : public Pass
{
public:
    void run(CompilerContext&) override;
};

#endif //GCC_LEXERPASS_HPP
