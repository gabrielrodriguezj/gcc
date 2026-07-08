#ifndef GCC_COMPILEROPTIONS_HPP
#define GCC_COMPILEROPTIONS_HPP
#include <filesystem>

struct CompilerOptions
{
    std::filesystem::path inputFile;
    bool runLexer;
    bool runParser;
    bool generateCode;
    bool emitCode;

    /*
    std::filesystem::path outputFile;
    bool emitAST = false;
    bool emitIR = false;
    bool optimize = false;

    bool dumpTokens;
    bool dumpAST;
    bool dumpIR;
    bool optimize;
    bool emitAssembly;
    bool emitObject;
    bool verbose;
    int optimizationLevel;*/
};

#endif //GCC_COMPILEROPTIONS_HPP
