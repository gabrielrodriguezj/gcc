#ifndef GCC_TOKEN_HPP
#define GCC_TOKEN_HPP

typedef enum {
    // Single-character tokens.
    LEFT_PAREN, RIGHT_PAREN,
    LEFT_BRACE, RIGHT_BRACE,
    COMMA, DOT, MINUS, PLUS,
    SEMICOLON, SLASH, STAR,

    // One or two character tokens.
    BANG, BANG_EQUAL,
    EQUAL, EQUAL_EQUAL,
    GREATER, GREATER_EQUAL,
    LESS, LESS_EQUAL,

    // Literals.
    IDENTIFIER, STRING, NUMBER,

    // Keywords. (true and false are officially reserved keywords in modern C,
    // specifically since the C23 standard)
    AND, ELSE, FALSE,
    FOR, IF, OR,
    RETURN, TRUE, WHILE,

    // Data types
    INT, VOID,

    ERROR, END
  } TokenName;

typedef struct {
    TokenName type;
    int offset;
    int length;
    int line;
} Token;

#endif //GCC_TOKEN_HPP
