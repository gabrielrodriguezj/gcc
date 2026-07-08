#include "gcc/driver/CompilerDriver.hpp"

int main(const int argc, char **argv) {
    CompilerDriver compiler;
    return compiler.run(argc, argv);
}

/*

std::filesystem::path changeExtension(
    const std::filesystem::path& inputPath,
    const std::string& newExtension)
{
    std::filesystem::path output = inputPath;
    output.replace_extension(newExtension);
    return output;
}

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
        std::filesystem::path input = argv[1];

        // Creating the source manager
        SourceManager source(input);

        // Creating lexer
        Lexer lexer(source);

        // Creating parser
        Parser parser(lexer);

        // Parsing the code
        ProgramAST ast = parser.parse();

        // Printing the ast
        AstPrinter printer(std::cout, source);
        printer.print(ast);

        // ofstream instance for saving the asm file.
        auto outputFile = changeExtension(input, ".asm");
        std::ofstream out(outputFile, std::ios::out | std::ios::trunc);
        if (!out.is_open()) {
            throw std::runtime_error("The output file could not be opened.");
        }

        // Emitting masm x86 assembler
        MASMx64CodeGenerator generator(out, source);
        generator.generate(ast);

    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return -1;
    }
 */