#include "gcc/parser/Parser.hpp"

#include <sstream>
#include <stdexcept>

Parser::Parser(Lexer &lexer) : lexer(lexer) {

}

bool Parser::parse() {
    currentToken = lexer.next();
    program();

    if (currentToken.name != TokenName::END) {
        return false;
    }
    return true;
}

void Parser::program() {
    function();
}

void Parser::function() {
    match(TokenName::INT);
    match(TokenName::IDENTIFIER);
    match(TokenName::LEFT_PAREN);
    match(TokenName::VOID);
    match(TokenName::RIGHT_PAREN);
    match(TokenName::LEFT_BRACE);
    statement();
    match(TokenName::RIGHT_BRACE);
}

void Parser::statement() {
    match(TokenName::RETURN);
    expression();
    match(TokenName::SEMICOLON);
}

void Parser::expression() {
    match(TokenName::NUMBER);
}

void Parser::match(TokenName tokenName) {
    if (tokenName == currentToken.name) {
        currentToken = lexer.next();
        return;
    }

    std::stringstream ss;
    ss<<"Error: Found " << to_string(currentToken.name) << " token instead of "
    << to_string(tokenName) <<". Line: " << currentToken.line << ".";
    throw std::runtime_error (ss.str());;
    //return false;
}


