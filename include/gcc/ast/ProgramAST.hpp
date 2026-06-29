#ifndef GCC_PROGRAM_HPP
#define GCC_PROGRAM_HPP
#include "Expression.hpp"
#include "Statement.hpp"

class ProgramAST: virtual public Statement {
public:
    ProgramAST(std::unique_ptr<Statement> );
    void accept(Visitor&) override;

    Statement& getFunction();
private:
    std::unique_ptr<Statement> function;
};

#endif //GCC_PROGRAM_HPP
