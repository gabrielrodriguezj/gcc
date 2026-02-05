#ifndef GCC_SCANNER_H
#define GCC_SCANNER_H


#include <string>
#include "core/token/token.h"

class Scanner {
    std::string source;
    int line;
    int current;

    bool match(char);
    bool isAtEnd() const;
    void skipWhitespace();
    char peek();
    char advance();
    char peekNext();

    Token* identifier();
    TokenKind identifierType(const std::string);
    Token* number();
    Token* string();

public:
    explicit Scanner(const std::string &source);
    Token* nextToken();
};


#endif //GCC_SCANNER_H