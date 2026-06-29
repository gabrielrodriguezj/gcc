#ifndef GCC_ASTPRINTER_HPP
#define GCC_ASTPRINTER_HPP
#include <ostream>

#include "Visitor.hpp"
#include "gcc/source/SourceManager.hpp"

class AstPrinter: public Visitor {
public:

    AstPrinter(std::ostream& out, const SourceManager& sourceManager);
    void visit(ConstantExpr& expr) override;
    void visit(FunctionStmt& stmt) override;
    void visit(ReturnStmt& stmt) override;
    void visit(ProgramAST& stmt) override;

private:
    std::ostream& out;
    const SourceManager& sourceManager;
    int indent = 0;
};

#endif //GCC_ASTPRINTER_HPP
