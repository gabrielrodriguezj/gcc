#include "gcc/driver/CommandLineParser.hpp"

#include <string_view>

CompilerOptions CommandLineParser::parse(int argc, char* argv[]) {
    if (argc < 2) {
        throw std::runtime_error("Fatal error: no input files.");
    }

    bool fileIncluded = false;
    CompilerOptions options;
    options.runLexer = true;
    options.runParser = true;
    options.generateCode = true;
    options.emitCode = true;


    for (int i = 1; i < argc; ++i) {
        std::string_view arg(argv[i]);

        if (arg == "--lex") {
            // Directs it to run the lexer, but stop before parsing
            options.runParser = false;
            options.generateCode = false;
            options.emitCode = false;
        }
        else if (arg == "--parse"){
            // Directs it to run the lexer and parser, but stop
            // before assembly generation
            options.generateCode = false;
            options.emitCode = false;
        }
        else if (arg == "--codegen") {
            // Directs it to perform lexing, parsing, and assembly
            // generation, but stop before code emission
            options.emitCode = false;
        }
        else if (arg == "-S") {
            // Directs your compiler to emit an assembly file,
            // but not assemble or link it.
        }
        else if (!arg.empty() && arg[0] == '-'){
            throw std::runtime_error("Unknown option.");
        }
        else {
            // Source file
            std::filesystem::path input = arg;
            options.inputFile = input;
            fileIncluded = true;
        }
    }

    if (!fileIncluded) {
        throw std::runtime_error("Fatal error: no input files.");
    }

    return options;
}
