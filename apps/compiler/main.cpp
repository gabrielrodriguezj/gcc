#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "gcc/lexer/Lexer.hpp"
#include "gcc/parser/Parser.hpp"
#include "gcc/source/SourceManager.hpp"
#include "gcc/visitors/AstPrinter.hpp"

std::string readFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
    {
        throw std::runtime_error("Could not open file: " + filename);
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    return buffer.str();
}

int main(const int argc, const char* argv[]) {
    if(argc == 1) {
        std::cerr << "Error: no input files";
        exit(64);
    }

    if (argc != 2) {
        std::cerr << "Currently, only one parameter is supported";
        exit(64);
    }

    try
    {
        // Reading the source code and creating the source manager
        std::string sourceCode = readFile(argv[1]);
        SourceManager source(sourceCode);

        // Creating lexer
        Lexer lexer(source);

        // Creating parser
        Parser parser(lexer);

        // Parsing the code
        ProgramAST ast = parser.parse();

        // Printing the ast
        AstPrinter printer(std::cout, source);
        ast.accept(printer);

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}