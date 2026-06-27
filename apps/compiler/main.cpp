#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

#include "gcc/lexer/Lexer.hpp"
#include "gcc/parser/Parser.hpp"
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
        std::string sourceCode = readFile(argv[1]);

        Lexer lexer(sourceCode);
        Parser parser(lexer);

        ProgramAST ast = parser.parse();

        AstPrinter printer(std::cout);
        ast.accept(printer);

        int a = 0;

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}