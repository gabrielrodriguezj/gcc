#ifndef GCC_CONSOLEDIAGNOSTICCONSUMER_HPP
#define GCC_CONSOLEDIAGNOSTICCONSUMER_HPP
#include "DiagnosticConsumer.hpp"
#include "../formatters/DiagnosticFormatter.hpp"

class ConsoleDiagnosticConsumer: public DiagnosticConsumer {
public:
    explicit ConsoleDiagnosticConsumer(
        DiagnosticFormatter&);
    void consume(const Diagnostic&) override;
private:
    const DiagnosticFormatter& formatter_;
};

#endif //GCC_CONSOLEDIAGNOSTICCONSUMER_HPP
