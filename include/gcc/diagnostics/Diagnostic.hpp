#ifndef GCC_DIAGNOSTIC_HPP
#define GCC_DIAGNOSTIC_HPP
#include <string>

#include "gcc/source/SourceLocation.hpp"

enum class DiagnosticSeverity
{
    Note,
    Warning,
    Error,
};

class Diagnostic
{
public:
    DiagnosticSeverity severity;
    SourceLocation location;
    std::string message;
};

#endif //GCC_DIAGNOSTIC_HPP
