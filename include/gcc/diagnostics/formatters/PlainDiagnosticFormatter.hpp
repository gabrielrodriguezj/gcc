#ifndef GCC_CLASSICDIAGNOSTICFORMATTER_HPP
#define GCC_CLASSICDIAGNOSTICFORMATTER_HPP
#include "../Diagnostic.hpp"
#include "DiagnosticFormatter.hpp"

class PlainDiagnosticFormatter: public DiagnosticFormatter {
public:
    explicit PlainDiagnosticFormatter(const SourceManager& sourceManager);
    std::string format(const Diagnostic& diagnostic) const override;

private:
    const SourceManager& sourceManager_;
};
#endif //GCC_CLASSICDIAGNOSTICFORMATTER_HPP
