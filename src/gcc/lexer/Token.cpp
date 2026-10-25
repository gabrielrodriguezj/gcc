#include "gcc/lexer/Token.hpp"

#include <ostream>

// Function to get the string representation
std::ostream& operator<<(std::ostream& os, TokenName name) {
    switch (name) {
        case TokenName::LEFT_PAREN:             return os << "'('";
        case TokenName::RIGHT_PAREN:            return os << "')'";
        case TokenName::LEFT_BRACE:             return os << "'{'";
        case TokenName::RIGHT_BRACE:            return os << "'}'";
        case TokenName::COMMA:                  return os << "','";
        case TokenName::DOT:                    return os << "'.'";
        case TokenName::MINUS:                  return os << "'-'";
        case TokenName::PLUS:                   return os << "'+'";
        case TokenName::SEMICOLON:              return os << "';'";
        case TokenName::SLASH:                  return os << "'/'";
        case TokenName::STAR:                   return os << "'*'";
        case TokenName::BANG:                   return os << "'!'";
        case TokenName::BANG_EQUAL:             return os << "'!='";
        case TokenName::EQUAL:                  return os << "'='";
        case TokenName::EQUAL_EQUAL:            return os << "'=='";
        case TokenName::GREATER:                return os << "'>'";
        case TokenName::GREATER_EQUAL:          return os << "'>='";
        case TokenName::LESS:                   return os << "'<'";
        case TokenName::LESS_EQUAL:             return os << "'<='";
        case TokenName::IDENTIFIER:             return os << "'identifier'";
        case TokenName::STRING:                 return os << "'string'";
        case TokenName::NUMBER:                 return os << "'number'";
        case TokenName::AND:                    return os << "'&&'";
        case TokenName::ELSE:                   return os << "'else'";
        case TokenName::FALSE:                  return os << "'false'";
        case TokenName::FOR:                    return os << "'for'";
        case TokenName::IF:                     return os << "'if'";
        case TokenName::OR:                     return os << "'||'";
        case TokenName::RETURN:                 return os << "'return'";
        case TokenName::TRUE:                   return os << "'true'";
        case TokenName::WHILE:                  return os << "'while'";
        case TokenName::INT:                    return os << "'int'";
        case TokenName::VOID:                   return os << "'void'";
        case TokenName::BITWISE_COMPLEMENT:     return os << "'~'";
        case TokenName::END:                    return os << "'$'";
        case TokenName::ERROR:                  return os << "'error'";
        default:                                return os << "Unknown";
    }
}

std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << "Token { "
       << "name = " << token.name
       << ", offset = " << token.offset
       << ", length = " << token.length
       << ", line = " << token.line
       << " }";

    return os;
}
