
#include <utility>

#include "gcc/diagnostics/DiagnosticEngine.hpp"

#include <iostream>

DiagnosticEngine::DiagnosticEngine(
    DiagnosticConsumer& consumer, DiagnosticEmissionMode mode):
    consumer_(consumer), mode_(mode){}

void DiagnosticEngine::flush() {

    while (emittedCount_ < diagnostics_.size()) {
        consumer_.consume(diagnostics_[emittedCount_]);
        ++emittedCount_;
    }
}

void DiagnosticEngine::report( DiagnosticSeverity severity,
                               SourceLocation location,
                               std::string message) {

    Diagnostic diagnostic;
    diagnostic.severity = severity;
    diagnostic.location = location;
    diagnostic.message = std::move(message);
    diagnostics_.push_back(std::move(diagnostic));

    if (mode_ == DiagnosticEmissionMode::Immediate) {
        flush();
    }
}


void DiagnosticEngine::error(
    SourceLocation location,
    std::string message) {

    ++errorCount_;
    report(DiagnosticSeverity::Error, location, std::move(message));
}

void DiagnosticEngine::warning(
    SourceLocation location,
    std::string message) {

    ++warningCount_;
    report(DiagnosticSeverity::Warning, location, std::move(message));
}

void DiagnosticEngine::note(
    SourceLocation location,
    std::string message) {

    ++noteCount_;
    report(DiagnosticSeverity::Note, location, std::move(message));
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
