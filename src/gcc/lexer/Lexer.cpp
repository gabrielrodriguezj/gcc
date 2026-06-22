#include "../../../include/gcc/lexer/Lexer.hpp"

#include <cstring>
#include <sstream>

Lexer::Lexer(std::string source)
    : source_(std::move(source)),
      current(0),
      start(0),
      line(1)
{
}

Token Lexer::next() {
    skipWhitespace();
    start = current;

    if (isAtEnd()) return makeToken(TokenName::END);

    char c = advance();

    if (isalpha(c)) return identifier();
    if(isdigit(c)) return number();

    switch (c) {
        case '(': return makeToken(TokenName::LEFT_PAREN);
        case ')': return makeToken(TokenName::RIGHT_PAREN);
        case '{': return makeToken(TokenName::LEFT_BRACE);
        case '}': return makeToken(TokenName::RIGHT_BRACE);
        case ';': return makeToken(TokenName::SEMICOLON);
        case ',': return makeToken(TokenName::COMMA);
        case '.': return makeToken(TokenName::DOT);
        case '-': return makeToken(TokenName::MINUS);
        case '+': return makeToken(TokenName::PLUS);
        case '/': return makeToken(TokenName::SLASH);
        case '*': return makeToken(TokenName::STAR);
        case '!':
            return makeToken(
                    match('=') ? TokenName::BANG_EQUAL : TokenName::BANG);
        case '=':
            return makeToken(
                    match('=') ? TokenName::EQUAL_EQUAL : TokenName::EQUAL);
        case '<':
            return makeToken(
                    match('=') ? TokenName::LESS_EQUAL : TokenName::LESS);
        case '>':
            return makeToken(
                    match('=') ? TokenName::GREATER_EQUAL : TokenName::GREATER);
        case '"': return string();
        default:
            std::stringstream ss;
            ss<<"Error: character '" << peek() << "' not valid. Line: " << line;
            throw std::runtime_error (ss.str());;
    }

}

void Lexer::skipWhitespace() {
    for (;;) {
        switch (peek()) {
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
                    // A single line comment ends with a line break
                    while (peek() != '\n' && !isAtEnd()) advance();
                }
                else if (peekNext() == '*') {
                    // consume the pattern "/*"
                    advance();
                    advance();
                    // A multi-line comment ends with a "*/"
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

Token Lexer::identifier() {
    while (isalpha(peek()) || isdigit(peek())) advance();

    std::string lexem = source_.substr(start, current - start);
    TokenName tokenName = identifierType(lexem);

    if(tokenName == TokenName::IDENTIFIER){
        return makeToken(TokenName::IDENTIFIER);
    }
    return makeToken(tokenName);
}

TokenName Lexer::identifierType(const std::string& lexeme){
    if(lexeme == "else") return TokenName::ELSE;
    if(lexeme == "false") return TokenName::FALSE;
    if(lexeme == "for") return TokenName::FOR;
    if(lexeme == "if") return TokenName::IF;
    if(lexeme == "int") return TokenName::INT;
    if(lexeme == "return") return TokenName::RETURN;
    if(lexeme == "true") return TokenName::TRUE;
    if(lexeme == "void") return TokenName::VOID;
    if(lexeme == "while") return TokenName::WHILE;
    return TokenName::IDENTIFIER;
}

Token Lexer::number() {
    while (isdigit(peek())) advance();

    // Checar si existe parte decimal
    if (peek() == '.' && isdigit(peekNext())) {
        // Consumir el "."
        advance();

        while (isdigit(peek())) advance();
    }
    if(peek() == 'E' && (peekNext() == '+' || peekNext() == '-'  || isdigit(peekNext()))){
        // consumir el "E"
        advance();

        if((peek() == '+' || peek() == '-'  )){
            advance();
        }
        while (isdigit(peek())) advance();
    }

    return makeToken(TokenName::NUMBER);
}

Token Lexer::string() {
    while (peek() != '"' && !isAtEnd()) {
        if (peek() == '\n') line++;
        advance();
    }
    if (isAtEnd()) {
        //return new Token(TokenName::ERROR, line);
        std::stringstream ss;
        ss << "Error: The \" that is missing. Line: " << line;
        throw std::runtime_error(ss.str());
    }

    // La comilla que cierra.
    advance();

    return makeToken(TokenName::STRING);
}

// auxiliary functions:

bool Lexer::match(char expected) {
    if (isAtEnd()) return false;
    if (source_.at(current) != expected) return false;
    current++;
    return true;
}

bool Lexer::isAtEnd() const {
    if (source_.length() <= current) return true;
    return source_.at(current) == '\0';
}

char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return source_.at(current);
}

char Lexer::advance() {
    current++;
    return source_.at(current-1);
}

char Lexer::peekNext() const {
    if (isAtEnd()) return '\0';
    return source_.at(current+1);
}


Token Lexer::makeToken(TokenName name) const {
    Token token;
    token.name = name;
    token.offset = start;
    token.length = current - start;
    token.line = line;

    return token;
}