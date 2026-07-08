#ifndef GCC_DIAGNOSTICFORMATTER_HPP
#define GCC_DIAGNOSTICFORMATTER_HPP
#include <string>

#include "../Diagnostic.hpp"
#include "gcc/source/SourceManager.hpp"
class DiagnosticFormatter
{
public:
    virtual ~DiagnosticFormatter() = default;

    [[nodiscard]]
    virtual std::string format(
        const Diagnostic& diagnostic) const = 0;
protected:
    virtual std::string severityToString( const Diagnostic& diagnostic) const {
        switch (diagnostic.severity)
        {
            case DiagnosticSeverity::Note:
                return "note";

            case DiagnosticSeverity::Warning:
                return "warning";

            case DiagnosticSeverity::Error:
                return "error";
        }

        return "unknown";
    }
};

#endif //GCC_DIAGNOSTICFORMATTER_HPP
