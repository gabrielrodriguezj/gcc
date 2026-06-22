#ifndef GCC_RETURNSTMT_HPP
#define GCC_RETURNSTMT_HPP
#include "Expression.hpp"
#include "Statement.hpp"

class ReturnStmt : public Statement {
public:
    ReturnStmt(const Expression &);

private:
    Expression expression;
};

#endif //GCC_RETURNSTMT_HPP
