#include <sstream>
#include "Scanner.h"

#include "core/exception/ScannerException.h"

Scanner::Scanner(const std::string &source) : source(source) {
    this->source.append(" ");
    line = 1;
    current = 0;
}

bool Scanner::match(char expected) {
    if (isAtEnd()) return false;
    if (source.at(current) != expected) return false;
    current++;
    return true;
}

bool Scanner::isAtEnd() const {
    return current >= source.length();
}

void Scanner::skipWhitespace() {
    for (;;) {
        char c = peek();
        switch (c) {
            case ' ':
            case '\r':
            case '\t':
                advance();
                break;
            case '\n':
                line++;
                advance();
                break;
            case '/':
                if (peekNext() == '/') {
                    // A single-line comment ends with the "new line" character
                    while (peek() != '\n' && !isAtEnd()) advance();
                }
                else if (peekNext() == '*') {
                    // Consume the "/*"
                    advance();
                    advance();
                    // A multi-line comment  ends with "*/"
                    bool openComment = true;
                    do {
                        if (peek() == '*' && !isAtEnd()) advance();
                        if (peek() == '/') {
                            openComment = false;
                        }
                        advance();
                    }while (openComment);

                }
                else {
                    return;
                }
                break;
            default:
                return;
        }
    }
}

char Scanner::peek() {
    if (isAtEnd()) return '\0';
    char c = source.at(current);
    return c;
}

char Scanner::advance() {
    current++;
    return source.at(current-1);
}

char  Scanner::peekNext() {
    if (isAtEnd()) return '\0';
    char c = source.at(current + 1);
    return c;
}

Token* Scanner::identifier() {
    int begin = this->current - 1;
    while (isalpha(peek()) || isdigit(peek()) || peek() == '_') advance();
    int end = this->current - 1;
    std::string lexem = source.substr(begin, end - begin + 1);
    TokenKind tk = identifierType(lexem);

    if(tk == TokenKind::IDENTIFIER){
        return new Token(tk, lexem, line);
    }
    return new Token(tk, line);
}

TokenKind Scanner::identifierType(const std::string lexem){
    if(lexem == "return") return TokenKind::RETURN;
    if(lexem == "main") return TokenKind::MAIN;
    return TokenKind::IDENTIFIER;
}

Token* Scanner::number() {
    int begin = current-1;
    while (isdigit(peek())) advance();

    // Check if the number has decimal digits
    if (peek() == '.' && isdigit(peekNext())) {
        // Consuming the "."
        advance();

        while (isdigit(peek())) advance();
    }
    if(peek() == 'E' && (peekNext() == '+' || peekNext() == '-'  || isdigit(peekNext()))){
        // Consuming the "E"
        advance();

        if((peek() == '+' || peek() == '-'  )){
            advance();
        }
        while (isdigit(peek())) advance();
    }

    int end = current - 1;

    std::string lexeme = source.substr(begin, end-begin + 1);
    return new Token(TokenKind::NUMBER, lexeme, line);
}

Token* Scanner::string() {
    int begin = current-1;

    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }
    if (isAtEnd()) {
        std::stringstream ss;
        ss << "Error: La string is not closing properly. Line: " << line;
        throw new ScannerException(ss.str());
    }

    // Consuming the closing quote
    advance();

    int end = current - 1;
    return  new Token(TokenKind::STRING, source.substr(begin + 1, end - begin - 1), line);
}

Token* Scanner::nextToken() {
    skipWhitespace();

    if (isAtEnd()) return new Token(TokenKind::END, line);

    char c = advance();

    if (isalpha(c))
        return identifier();
    if(isdigit(c))
        return number();

    switch (c) {
        case '(': return new Token(TokenKind::LEFT_PAREN, line);
        case ')': return new Token(TokenKind::RIGHT_PAREN, line);
        case '{': return new Token(TokenKind::LEFT_BRACE, line);
        case '}': return new Token(TokenKind::RIGHT_BRACE, line);
        case ';': return new Token(TokenKind::SEMICOLON, line);
        case ',': return new Token(TokenKind::COMMA, line);
        case '.': return new Token(TokenKind::DOT, line);
        case '-': return new Token(TokenKind::MINUS, line);
        case '+': return new Token(TokenKind::PLUS, line);
        case '/': return new Token(TokenKind::SLASH, line);
        case '*': return new Token(TokenKind::STAR, line);
        case '!':
            return new Token(
                    match('=') ? TokenKind::BANG_EQUAL : TokenKind::BANG, line);
        case '=':
            return new Token(
                    match('=') ? TokenKind::EQUAL_EQUAL : TokenKind::EQUAL, line);
        case '<':
            return new Token(
                    match('=') ? TokenKind::LESS_EQUAL : TokenKind::LESS, line);
        case '>':
            return new Token(
                    match('=') ? TokenKind::GREATER_EQUAL : TokenKind::GREATER, line);
        case '"': return string();
    }

    std::stringstream ss;
    ss<<"Error: character '" << peek() << "' not valid. Line: " << line;
    throw new ScannerException(ss.str());
}
