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

// Function to get the string representation
constexpr std::string_view to_string(TokenName tokenName) {
    switch (tokenName) {
        case TokenName::LEFT_PAREN:     return "'('";
        case TokenName::RIGHT_PAREN:    return "')'";
        case TokenName::LEFT_BRACE:     return "'{'";
        case TokenName::RIGHT_BRACE:    return "'}'";
        case TokenName::COMMA:          return "','";
        case TokenName::DOT:            return "'.'";
        case TokenName::MINUS:          return "'-'";
        case TokenName::PLUS:           return "'+'";
        case TokenName::SEMICOLON:      return "';'";
        case TokenName::SLASH:          return "'/'";
        case TokenName::STAR:           return "'*'";
        case TokenName::BANG:           return "'!'";
        case TokenName::BANG_EQUAL:     return "'!='";
        case TokenName::EQUAL:          return "'='";
        case TokenName::EQUAL_EQUAL:    return "'=='";
        case TokenName::GREATER:        return "'>'";
        case TokenName::GREATER_EQUAL:  return "'>='";
        case TokenName::LESS:           return "'<'";
        case TokenName::LESS_EQUAL:     return "'<='";
        case TokenName::IDENTIFIER:     return "'identifier'";
        case TokenName::STRING:         return "'string'";
        case TokenName::NUMBER:         return "'number'";
        case TokenName::AND:            return "'&&'";
        case TokenName::ELSE:           return "'else'";
        case TokenName::FALSE:          return "'false'";
        case TokenName::FOR:            return "'for'";
        case TokenName::IF:             return "'if'";
        case TokenName::OR:             return "'||'";
        case TokenName::RETURN:         return "'return'";
        case TokenName::TRUE:           return "'true'";
        case TokenName::WHILE:          return "'while'";
        case TokenName::INT:          return "'int'";
        case TokenName::VOID:          return "'void'";
        case TokenName::END:          return "'$'";
        case TokenName::ERROR:          return "'error'";
        default:                        return "Unknown";
    }
}

#endif //GCC_TOKEN_HPP
