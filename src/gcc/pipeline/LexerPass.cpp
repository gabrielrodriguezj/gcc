#include "gcc/pipeline/LexerPass.hpp"

#include <iostream>

void LexerPass::run(CompilerContext& ctx) {
    const auto& sm = ctx.sourceManager();
    auto& de = ctx.diagnosticEngine();
    Lexer lexer(sm, de);

    // Execute the lexer pass
    while (true) {
        auto token = lexer.next();
        std::cout << token << std::endl;

        if (token.name == TokenName::END) {
            break;
        }
    }
}
