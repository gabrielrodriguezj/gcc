#ifndef GCC_DIAGNOSTICSENGINE_HPP
#define GCC_DIAGNOSTICSENGINE_HPP
#include "consumers/DiagnosticConsumer.hpp"
#include "formatters/DiagnosticFormatter.hpp"
#include "gcc/source/SourceManager.hpp"

class DiagnosticEngine
{
public:
    explicit DiagnosticEngine(DiagnosticConsumer&);
    void error(SourceLocation location, std::string_view message);
    void warning(SourceLocation location, std::string_view message);
    void note(SourceLocation location, std::string_view message);

    std::size_t errorCount() const;
    std::size_t warningCount() const;
    bool hasErrors() const;

private:
    DiagnosticConsumer& consumer_;

    std::size_t errorCount_ = 0;
    std::size_t warningCount_ = 0;
};

#endif //GCC_DIAGNOSTICSENGINE_HPP
