#ifndef GCC_COMPILERCONTEXT_HPP
#define GCC_COMPILERCONTEXT_HPP
#include "CompilerOptions.hpp"
#include "gcc/ast/ProgramAST.hpp"
#include "gcc/source/SourceManager.hpp"

class CompilerContext {
public:
    explicit CompilerContext(CompilerOptions, std::unique_ptr<SourceManager>);
    CompilerOptions& options();
    SourceManager* sourceManager() const;
    ProgramAST* ast() const;
    void setAST(std::unique_ptr<ProgramAST> ast);

private:
    CompilerOptions options_;
    std::unique_ptr<SourceManager> sourceManager_;
    std::unique_ptr<ProgramAST> ast_;

    // Other options:
    // -- CompilerContext&
    // DiagnosticEngine diagnostics;
    // Diagnostics diagnostics;
    // CompilerOptions options;
    // SymbolTable symbols;
    // TargetInfo target;
    // IRModule ir;
    // std::unique_ptr<DiagnosticsEngine> diagnostics_;
    // std::unique_ptr<Module> ir_;

};

#endif //GCC_COMPILERCONTEXT_HPP
