#include "../../../include/gcc/core/CompilerContext.hpp"

CompilerContext::CompilerContext(
    const CompilerOptions &options,
        SourceManager& sourceManager,
        DiagnosticEngine& diagnosticEngine):
        options_(options),
        sourceManager_(sourceManager),
        diagnostic_(diagnosticEngine){

}

CompilerOptions& CompilerContext::options() {
    return options_;
}

SourceManager& CompilerContext::sourceManager() {
    return sourceManager_;
}

DiagnosticEngine& CompilerContext::diagnosticEngine() {
    return diagnostic_;
}

ProgramAST* CompilerContext::ast() const {
    return ast_.get();
}

void CompilerContext::setAST(std::unique_ptr<ProgramAST> ast) {
    ast_ = std::move(ast);
}

