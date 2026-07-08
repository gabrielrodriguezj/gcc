#ifndef GCC_DIAGNOSTICCONSUMER_HPP
#define GCC_DIAGNOSTICCONSUMER_HPP
#include "../Diagnostic.hpp"

class DiagnosticConsumer
{
public:
    virtual ~DiagnosticConsumer() = default;

    virtual void consume(const Diagnostic&) = 0;
};

#endif //GCC_DIAGNOSTICCONSUMER_HPP
