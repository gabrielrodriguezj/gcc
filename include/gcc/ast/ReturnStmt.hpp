#ifndef GCC_RETURNSTMT_HPP
#define GCC_RETURNSTMT_HPP

#include "Expression.hpp"
#include "Statement.hpp"

class ReturnStmt : public Statement {
public:
    ReturnStmt(std::unique_ptr<Expression>);
    void accept(Visitor &visitor) override;

private:
    std::unique_ptr<Expression> expression;
};

#endif //GCC_RETURNSTMT_HPP
