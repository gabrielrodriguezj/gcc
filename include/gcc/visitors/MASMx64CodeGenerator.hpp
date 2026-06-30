#ifndef GCC_MASMX64CODEGENERATOR_HPP
#define GCC_MASMX64CODEGENERATOR_HPP

#include <iosfwd>

#include "Visitor.hpp"
#include "gcc/source/SourceManager.hpp"

class MASMx64CodeGenerator : public Visitor {
public:
    explicit MASMx64CodeGenerator(std::ostream& out, SourceManager& sourceManager);
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
    void emitLine(const std::string&) const;
    void emitLineIndented(const std::string&) const;
};


#endif //GCC_MASMX64CODEGENERATOR_HPP
