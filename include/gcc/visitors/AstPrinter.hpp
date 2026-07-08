#ifndef GCC_ASTPRINTER_HPP
#define GCC_ASTPRINTER_HPP
#include <ostream>

#include "Visitor.hpp"
#include "gcc/ast/UnaryExpr.hpp"
#include "gcc/source/SourceManager.hpp"

class AstPrinter: public Visitor {
public:

    AstPrinter(std::ostream& out, const SourceManager& sourceManager);
    void print(ProgramAST& stmt);

    void visit(ConstantExpr& expr) override;
    void visit(UnaryExpr& stmt) override;
    void visit(FunctionStmt& stmt) override;
    void visit(ReturnStmt& stmt) override;
    void visit(ProgramAST& stmt) override;

private:
    std::ostream& out_;
    const SourceManager& sourceManager_;
    int indent_ = 0;
};

#endif //GCC_ASTPRINTER_HPP
