#ifndef GCC_PARSER_HPP
#define GCC_PARSER_HPP

#include <memory>

#include "gcc/ast/Expression.hpp"
#include "gcc/ast/FunctionStmt.hpp"
#include "gcc/ast/ProgramAST.hpp"
#include "gcc/ast/Statement.hpp"
#include "gcc/lexer/Lexer.hpp"

class Parser {
public:
    Parser(Lexer&);
    ProgramAST parse();

private:
    Lexer lexer_;
    Token currentToken_;

    ProgramAST program();
    std::unique_ptr<FunctionStmt> function();
    std::unique_ptr<Statement> statement();
    std::unique_ptr<Expression> expression();
    std::unique_ptr<Expression> unary();

    void match(TokenName);
};
#endif //GCC_PARSER_HPP
