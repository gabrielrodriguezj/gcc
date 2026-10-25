#include "gcc/driver/CompilerDriver.hpp"

int main(const int argc, char **argv) {
    CompilerDriver compiler;
    return compiler.run(argc, argv);
}