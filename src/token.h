#ifndef GCC_TOKEN_H
#define GCC_TOKEN_H

typedef enum {
    // Single-character tokens.
    TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
    TOKEN_LEFT_BRACE, TOKEN_RIGHT_BRACE,
    TOKEN_COMMA, TOKEN_DOT, TOKEN_MINUS, TOKEN_PLUS,
    TOKEN_SEMICOLON, TOKEN_SLASH, TOKEN_STAR,

    // One or two character tokens.
    TOKEN_AND, TOKEN_BANG, TOKEN_BANG_EQUAL,
    TOKEN_EQUAL, TOKEN_EQUAL_EQUAL,
    TOKEN_GREATER, TOKEN_GREATER_EQUAL,
    TOKEN_LESS, TOKEN_LESS_EQUAL, TOKEN_OR,

    // Literals.
    TOKEN_IDENTIFIER, TOKEN_STRING, TOKEN_NUMBER,

    // Keywords.
    TOKEN_ELSE, TOKEN_FALSE,
    TOKEN_FOR, TOKEN_IF, TOKEN_NULL,
    TOKEN_RETURN, TOKEN_TRUE, TOKEN_WHILE,

    TOKEN_EOF
} token_type_t;

typedef struct {
    token_type_t type;
    const char* start;
    int length;
    int line;
} token_t;

void print_token(token_t);

#endif //GCC_TOKEN_H