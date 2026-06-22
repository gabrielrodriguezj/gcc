#ifndef GCC_PROGRAM_HPP
#define GCC_PROGRAM_HPP
#include "Statement.hpp"

class ProgramAST {
public:
    ProgramAST(Statement &);
private:
    Statement function;
};

#endif //GCC_PROGRAM_HPP
