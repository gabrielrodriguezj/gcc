#ifndef GCC_LEXER_HPP
#define GCC_LEXER_HPP

#include "Token.hpp"
#include "../diagnostics/DiagnosticEngine.hpp"
#include "gcc/source/SourceManager.hpp"

/**
 * On-demand lexical analysis (lazy tokenization): the lexer produces the next
 * token when the parser requests it.
 */
class Lexer {
public:
    explicit Lexer(const SourceManager&, DiagnosticEngine&);
    Token next();

private:
    const SourceManager& sourceManager_;
    DiagnosticEngine& diagnostics_;
    std::string_view source_;
    size_t current_;
    size_t start_;
    size_t line_;

    void skipWhitespace();
    Token identifier();
    static TokenName identifierType(std::string_view);
    Token number();
    Token string();

    bool match(char);
    bool isAtEnd() const;
    char peek() const;
    char advance();
    char peekNext() const;
    Token makeToken(TokenName) const;
};

/*
 * In the context of computer science and compilers, lexer and scanner are
 * often used interchangeably to refer to the same component: the lexical
 * analyzer. They take raw source code and convert a sequence of characters
 * into a sequence of meaningful chunks called tokens.
 *
 * Scanner: Performs the initial, physical pass. It reads raw characters
 * character-by-character, discards meaningless elements like whitespaces and
 * comments, and groups the remaining characters into abstract categories.
 *
 * Lexer: Takes the basic sequences from the scanner and attaches actual values
 * to them. It formally binds categories (e.g., keyword, variable) to the text
 * (or "lexeme") so they can be passed on to the parser.
 *
 */

#endif //GCC_LEXER_HPP
