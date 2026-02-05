#ifndef GCC_TOKEN_H
#define GCC_TOKEN_H

#include "TokenKind.h"
#include "TokenUtil.h"

class Token{
    TokenKind kind;
    std::string lexeme;
    int line;
public:
    ~Token() = default;

    Token(const TokenKind kind, const int line){
        this->kind = kind;
        this->line = line;
    }

    Token(const TokenKind kind, const std::string &lexeme, const int line){
        this->kind = kind;
        this->lexeme = lexeme;
        this->line = line;
    }

    TokenKind getKind() const {
        return kind;
    }

    std::string getLexeme() {
        return lexeme;
    }

    int getLine() const {
        return line;
    }

    std::string toString() const {
        std::stringstream ss;
        ss<<"<" << tokenKindToString(kind) <<
            (lexeme.empty()? "": ", " + lexeme) <<
                ", line: " << line << ">" << std::endl;
        return ss.str();
    }
};

#endif //GCC_TOKEN_H
