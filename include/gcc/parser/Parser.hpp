#ifndef GCC_PARSER_HPP
#define GCC_PARSER_HPP

#include "gcc/lexer/Lexer.hpp"

class Parser {
public:
    Parser(Lexer&);
    bool parse();

private:
    Lexer lexer;
    Token currentToken;

    void program();
    void function();
    void statement();
    void expression();

    void match(TokenName);
};
#endif //GCC_PARSER_HPP
