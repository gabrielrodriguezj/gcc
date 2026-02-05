#ifndef GCC_TOKENUTIL_H
#define GCC_TOKENUTIL_H

#include <string>
#include <sstream>
#include "TokenKind.h"

inline std::string tokenKindToString(TokenKind tk) {
    std::stringstream ss;

    switch (tk) {
        case TokenKind::LEFT_PAREN:
            ss << "(";
            break;
        case TokenKind::RIGHT_PAREN:
            ss << ")";
            break;
        case TokenKind::LEFT_BRACE:
            ss << "{";
            break;
        case TokenKind::RIGHT_BRACE:
            ss << "}";
            break;
        case TokenKind::COMMA:
            ss << ",";
            break;
        case TokenKind::DOT:
            ss << ".";
            break;
        case TokenKind::MINUS:
            ss << "-";
            break;
        case TokenKind::PLUS:
            ss << "+";
            break;
        case TokenKind::SEMICOLON:
            ss << ";";
            break;
        case TokenKind::SLASH:
            ss << "/";
            break;
        case TokenKind::STAR:
            ss << "*";
            break;
        case TokenKind::BANG:
            ss << "!";
            break;
        case TokenKind::BANG_EQUAL:
            ss << "!=";
            break;
        case TokenKind::EQUAL:
            ss << "=";
            break;
        case TokenKind::EQUAL_EQUAL:
            ss << "==";
            break;
        case TokenKind::GREATER:
            ss << ">";
            break;
        case TokenKind::GREATER_EQUAL:
            ss << ">=";
            break;
        case TokenKind::LESS:
            ss << "<";
            break;
        case TokenKind::LESS_EQUAL:
            ss << "<=";
            break;
        case TokenKind::IDENTIFIER:
            ss << "ID";
            break;
        case TokenKind::STRING:
            ss << "STRING";
            break;
        case TokenKind::NUMBER:
            ss << "NUMBER";
            break;
        case TokenKind::MAIN:
            ss << "MAIN";
            break;
        case TokenKind::RETURN:
            ss << "RETURN";
            break;
        case TokenKind::END:
            ss << "$";
            break;
        default:
            ss << "Error";
            break;
    }
    return ss.str();
}

#endif //GCC_TOKENUTIL_H