#ifndef GCC_DIAGNOSTICSENGINE_HPP
#define GCC_DIAGNOSTICSENGINE_HPP
#include "consumers/DiagnosticConsumer.hpp"
#include "formatters/DiagnosticFormatter.hpp"
#include "gcc/source/SourceManager.hpp"

class DiagnosticEngine {
public:
    explicit DiagnosticEngine(DiagnosticConsumer&, DiagnosticEmissionMode);
    void flush();

    void error(SourceLocation, std::string);
    void warning(SourceLocation, std::string);
    void note(SourceLocation, std::string);

    std::size_t errorCount() const;
    std::size_t warningCount() const;
    bool hasErrors() const;

    std::size_t getDiagnosticCount() const
    {
        return diagnostics_.size();
    }

private:
    DiagnosticConsumer& consumer_;

    std::size_t errorCount_ = 0;
    std::size_t warningCount_ = 0;
    std::size_t noteCount_ = 0;

    DiagnosticEmissionMode mode_;

    std::vector<Diagnostic> diagnostics_;
    size_t emittedCount_ = 0;

    void report(
        DiagnosticSeverity,
        SourceLocation,
        std::string
    );
};

#endif //GCC_DIAGNOSTICSENGINE_HPP
