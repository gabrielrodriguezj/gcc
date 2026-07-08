#include "../../../../include/gcc/diagnostics/consumers/ConsoleDiagnosticConsumer.hpp"

#include <iostream>

ConsoleDiagnosticConsumer::ConsoleDiagnosticConsumer(
    DiagnosticFormatter& formatter)
    : formatter_(formatter){
}

void ConsoleDiagnosticConsumer::consume(const Diagnostic& diagnostic){
    std::cerr
        << formatter_.format(diagnostic)
        << '\n';
}
