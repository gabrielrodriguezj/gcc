
#include "gcc/diagnostics/DiagnosticEngine.hpp"

DiagnosticEngine::DiagnosticEngine
    (DiagnosticConsumer& consumer): consumer_(consumer){
}

void DiagnosticEngine::error(
    SourceLocation location,
    std::string_view message)
{
    ++errorCount_;

    Diagnostic diagnostic;

    diagnostic.severity = DiagnosticSeverity::Error;
    diagnostic.location = location;
    diagnostic.message = std::string(message);

    consumer_.consume(diagnostic);
}

void DiagnosticEngine::warning(
    SourceLocation location,
    std::string_view message) {
    ++warningCount_;

    Diagnostic diagnostic;

    diagnostic.severity = DiagnosticSeverity::Warning;
    diagnostic.location = location;
    diagnostic.message = std::string(message);

    consumer_.consume(diagnostic);
}

void DiagnosticEngine::note(
    SourceLocation location,
    std::string_view message)
{
    //++note_;

    Diagnostic diagnostic;

    diagnostic.severity = DiagnosticSeverity::Note;
    diagnostic.location = location;
    diagnostic.message = std::string(message);

    consumer_.consume(diagnostic);
}

std::size_t DiagnosticEngine::errorCount() const {
    return errorCount_;
}
std::size_t DiagnosticEngine::warningCount() const {
    return warningCount_;
}
bool DiagnosticEngine::hasErrors() const {
    return errorCount_ > 0;
}
