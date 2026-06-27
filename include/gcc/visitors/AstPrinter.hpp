#ifndef GCC_ASTPRINTER_HPP
#define GCC_ASTPRINTER_HPP
#include <ostream>

#include "Visitor.hpp"

class AstPrinter: public Visitor {
public:

    explicit AstPrinter(std::ostream& out) : out(out) {}
    void visit(ConstantExpr& expr) override;
    void visit(FunctionStmt& stmt) override;
    void visit(ReturnStmt& stmt) override;
    void visit(ProgramAST& stmt) override;

private:
    std::ostream& out;
};

#endif //GCC_ASTPRINTER_HPP
