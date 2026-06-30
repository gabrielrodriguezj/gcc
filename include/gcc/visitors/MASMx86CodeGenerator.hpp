#ifndef GCC_MASMGENERATOR_HPP
#define GCC_MASMGENERATOR_HPP

#include <iosfwd>

#include "Visitor.hpp"
#include "gcc/source/SourceManager.hpp"

class MASMx86CodeGenerator : public Visitor {
public:
    explicit MASMx86CodeGenerator(std::ostream& out, SourceManager& sourceManager);
    void generate(ProgramAST& program);

    void visit(ConstantExpr& expr) override;
    void visit(FunctionStmt& stmt) override;
    void visit(ReturnStmt& stmt) override;
    void visit(ProgramAST& stmt) override;

private:
    std::ostream& out_;
    const SourceManager& sourceManager_;

    void emitHeader();
    void emitFooter() const;
    void emitLine(const std::string&);
};

#endif //GCC_MASMGENERATOR_HPP
