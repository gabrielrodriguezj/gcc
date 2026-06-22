#ifndef GCC_FUNCTIONNODE_HPP
#define GCC_FUNCTIONNODE_HPP

#include "Statement.hpp"

class FunctionStmt {
public:
    FunctionStmt(Token &, Statement &);

private:
    Token name;
    Statement body;
};

#endif //GCC_FUNCTIONNODE_HPP
