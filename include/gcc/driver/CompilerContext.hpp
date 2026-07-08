#ifndef GCC_COMPILERCONTEXT_HPP
#define GCC_COMPILERCONTEXT_HPP
#include "CompilerOptions.hpp"
#include "gcc/ast/ProgramAST.hpp"
#include "gcc/diagnostics/DiagnosticEngine.hpp"
#include "gcc/source/SourceManager.hpp"

class CompilerContext {
public:
    explicit CompilerContext(
        const CompilerOptions &,
        std::unique_ptr<SourceManager>,
        std::unique_ptr<DiagnosticEngine>);
    CompilerOptions& options();
    SourceManager* sourceManager() const;
    DiagnosticEngine* diagnosticEngine() const;
    ProgramAST* ast() const;
    void setAST(std::unique_ptr<ProgramAST> ast);

private:
    CompilerOptions options_;
    std::unique_ptr<SourceManager> sourceManager_;
    std::unique_ptr<DiagnosticEngine> diagnostic_;
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
