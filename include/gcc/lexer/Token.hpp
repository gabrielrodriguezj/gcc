#ifndef GCC_TOKEN_HPP
#define GCC_TOKEN_HPP

#include <string_view>

enum TokenName{
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, PLUS,
    SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL, MINUS, MINUS_MINUS,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords. (true and false are officially reserved keywords in modern C,
    // specifically since the C23 standard)
    AND, ELSE, FALSE,
    FOR, IF, OR,
    RETURN, TRUE, WHILE,

    // Data types
    INT, VOID,

    // Bit operators
    BITWISE_COMPLEMENT,

    ERROR, END
} ;

struct Token {
    TokenName name;
    int offset;
    int length;
    int line;
};

std::string_view toString(TokenName);
std::ostream& operator<<(std::ostream& os, TokenName);
std::ostream& operator<<(std::ostream& os, const Token&);

#endif //GCC_TOKEN_HPP
