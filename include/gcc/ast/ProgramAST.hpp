#ifndef GCC_PROGRAM_HPP
#define GCC_PROGRAM_HPP
#include "Statement.hpp"

class ProgramAST {
public:
    ProgramAST(std::unique_ptr<Statement> );
private:
    std::unique_ptr<Statement>  function;
};

#endif //GCC_PROGRAM_HPP
