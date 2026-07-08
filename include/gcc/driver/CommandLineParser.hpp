#ifndef GCC_COMMANDLINEPARSER_HPP
#define GCC_COMMANDLINEPARSER_HPP
#include "CompilerOptions.hpp"

class CommandLineParser
{
public:
    CompilerOptions parse(int argc, char* argv[]);
};

#endif //GCC_COMMANDLINEPARSER_HPP
