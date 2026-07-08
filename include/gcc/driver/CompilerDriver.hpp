#ifndef GCC_COMPILERDRIVER_HPP
#define GCC_COMPILERDRIVER_HPP
#include "CompilerOptions.hpp"
#include "gcc/pipeline/Pipeline.hpp"

class CompilerDriver
{
public:
    int run(int argc, char** argv);
private:
    Pipeline buildPipeline(const CompilerOptions&);
};

#endif //GCC_COMPILERDRIVER_HPP
