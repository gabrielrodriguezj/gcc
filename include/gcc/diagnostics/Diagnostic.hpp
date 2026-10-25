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

/**
 * Immediate: It sends the diagnostic to the consumer immediately (Eager reporting).
 * Deferred: It retains the diagnostic until flush() is invoked. (Lazy reporting)
 */
enum class DiagnosticEmissionMode {
    Immediate,
    Deferred
};

class Diagnostic
{
public:
    DiagnosticSeverity severity;
    SourceLocation location;
    std::string message;
};

#endif //GCC_DIAGNOSTIC_HPP
