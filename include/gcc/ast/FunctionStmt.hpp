#ifndef GCC_FUNCTIONNODE_HPP
#define GCC_FUNCTIONNODE_HPP

#include "Statement.hpp"

class FunctionStmt: public Statement {
public:
    FunctionStmt(Token &, std::unique_ptr<Statement>);
    void accept(Visitor &visitor) override;

private:
    Token name;
    std::unique_ptr<Statement> body;
};

#endif //GCC_FUNCTIONNODE_HPP
