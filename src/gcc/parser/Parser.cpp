#include "gcc/parser/Parser.hpp"

#include <sstream>
#include <stdexcept>

#include "gcc/ast/ConstantExpr.hpp"
#include "gcc/ast/ReturnStmt.hpp"
#include "gcc/ast/UnaryExpr.hpp"

Parser::Parser(Lexer &lexer) : lexer_(lexer) {

}

ProgramAST Parser::parse() {
    currentToken_ = lexer_.next();
    ProgramAST ast = program();

    if (currentToken_.name == TokenName::END) {
        return ast;
    }

    std::stringstream ss;
    ss<<"Error: Found. Line: " << currentToken_.line << ".";
    throw std::runtime_error (ss.str());;
}

ProgramAST Parser::program() {
    std::unique_ptr<Statement>  stmt = function();
    return ProgramAST(std::move(stmt));
}

std::unique_ptr<FunctionStmt> Parser::function() {
    match(TokenName::INT);
    Token name = currentToken_;
    match(TokenName::IDENTIFIER);
    match(TokenName::LEFT_PAREN);
    match(TokenName::VOID);
    match(TokenName::RIGHT_PAREN);
    match(TokenName::LEFT_BRACE);
    std::unique_ptr<Statement> body = statement();
    match(TokenName::RIGHT_BRACE);
    return std::make_unique<FunctionStmt>(name, std::move(body));
}

std::unique_ptr<Statement> Parser::statement() {
    match(TokenName::RETURN);
    std::unique_ptr<Expression> expr = expression();
    match(TokenName::SEMICOLON);
    return std::make_unique<ReturnStmt>(std::move(expr));
}

std::unique_ptr<Expression> Parser::expression() {
    Token token = currentToken_;
    if (currentToken_.name == TokenName::NUMBER) {
        match(TokenName::NUMBER);
        return std::make_unique<ConstantExpr>(token);
    }
    else if (currentToken_.name == TokenName::BITWISE_COMPLEMENT ||
        currentToken_.name == TokenName::MINUS) {
        return unary();
    }
    else if (currentToken_.name == TokenName::LEFT_PAREN) {
        match(TokenName::LEFT_PAREN);
        std::unique_ptr<Expression> innerExp = expression();
        match(TokenName::RIGHT_PAREN);
        return innerExp;
    }

    std::stringstream ss;
    ss << "Malformed expression. Line: " << currentToken_.line << ".";
    throw std::runtime_error (ss.str());
}

std::unique_ptr<Expression> Parser::unary() {
    Token token = currentToken_;
    std::unique_ptr<Expression> expr;
    if (currentToken_.name == TokenName::BITWISE_COMPLEMENT) {
        match(TokenName::BITWISE_COMPLEMENT);
        expr = expression();
    }
    else if (currentToken_.name == TokenName::MINUS) {
        match(TokenName::MINUS);
        expr = expression();
    }

    return std::make_unique<UnaryExpr>(token, std::move(expr));


}

void Parser::match(TokenName tokenName) {
    if (tokenName == currentToken_.name) {
        currentToken_ = lexer_.next();
        return;
    }

    std::stringstream ss;
    ss<<"Error: Found " << currentToken_.toString() << " token instead of "
    << currentToken_.toString() <<". Line: " << currentToken_.line << ".";
    throw std::runtime_error (ss.str());;
    //return false;
}


