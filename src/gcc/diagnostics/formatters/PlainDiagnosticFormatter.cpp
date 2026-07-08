#include "../../../../include/gcc/diagnostics/formatters/PlainDiagnosticFormatter.hpp"

PlainDiagnosticFormatter::PlainDiagnosticFormatter(
    const SourceManager& sourceManager)
    : sourceManager_(sourceManager){
}

std::string PlainDiagnosticFormatter::format(
    const Diagnostic& diagnostic) const {
    std::ostringstream out;

    out
        << sourceManager_.filename()
        << ':'
        << diagnostic.location.line
        << ':'
        << diagnostic.location.column
        << ": "
        << DiagnosticFormatter::severityToString(diagnostic)
        << ": "
        << diagnostic.message;

    return out.str();
}