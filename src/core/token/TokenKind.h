#ifndef GCC_TOKEN_NAME_H
#define GCC_TOKEN_NAME_H

enum class TokenKind {
    // One single character
    LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS, SEMICOLON, SLASH, STAR,

    // One or two characters
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals
    IDENTIFIER, STRING, NUMBER,

    // Keyword
    RETURN, MAIN,

    END,
};

#endif //GCC_TOKEN_NAME_H