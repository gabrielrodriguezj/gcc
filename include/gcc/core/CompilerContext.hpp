#ifndef GCC_COMPILERCONTEXT_HPP
#define GCC_COMPILERCONTEXT_HPP
#include "../driver/CompilerOptions.hpp"
#include "gcc/ast/ProgramAST.hpp"
#include "gcc/diagnostics/DiagnosticEngine.hpp"
#include "gcc/source/SourceManager.hpp"

class CompilerContext {
public:
    explicit CompilerContext(
        const CompilerOptions&,
        SourceManager&,
        DiagnosticEngine&);

    CompilerOptions& options();
    SourceManager& sourceManager();
    DiagnosticEngine& diagnosticEngine();
    ProgramAST* ast() const;
    void setAST(std::unique_ptr<ProgramAST> ast);

private:
    CompilerOptions options_;
    SourceManager& sourceManager_;
    DiagnosticEngine& diagnostic_;
    std::unique_ptr<ProgramAST> ast_;

    // Other options:
    // -- CompilerContext&
    //
    // SymbolTable symbols;
    // TargetInfo target;
    // IRModule ir;
    // std::unique_ptr<Module> ir_;

};

#endif //GCC_COMPILERCONTEXT_HPP
