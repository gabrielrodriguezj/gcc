#ifndef GCC_SOURCELOCATION_HPP
#define GCC_SOURCELOCATION_HPP
#include <cstddef>

struct SourceLocation {
    std::size_t offset = 0;
    std::size_t line = 1;
    std::size_t column = 1;
};

#endif //GCC_SOURCELOCATION_HPP
