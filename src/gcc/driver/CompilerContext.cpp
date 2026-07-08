#include "gcc/driver/CompilerContext.hpp"

CompilerContext::CompilerContext(const CompilerOptions options, std::unique_ptr<SourceManager> sourceManager):
    options_(options), sourceManager_(std::move(sourceManager)) {
}

CompilerOptions& CompilerContext::options() {
    return options_;
}

SourceManager* CompilerContext::sourceManager() const {
    return sourceManager_.get();
}

ProgramAST* CompilerContext::ast() const {
    return ast_.get();
}

void CompilerContext::setAST(std::unique_ptr<ProgramAST> ast) {
    ast_ = std::move(ast);
}

