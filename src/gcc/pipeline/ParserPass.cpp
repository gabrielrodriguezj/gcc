#include "gcc/pipeline/ParserPass.hpp"

#include <iostream>

#include "gcc/lexer/Lexer.hpp"
#include "gcc/parser/Parser.hpp"

void ParserPass::run(CompilerContext& ctx) {

    auto& sm = ctx.sourceManager();
    auto& de = ctx.diagnosticEngine();
    Lexer* lexer = new Lexer(sm, de);

    Parser* parser = new Parser(*lexer);
    auto a = parser->parse();

    auto b = lexer->next();
    std::cout << b << std::endl;
}
