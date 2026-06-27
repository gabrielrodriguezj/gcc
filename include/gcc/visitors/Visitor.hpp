#ifndef GCC_VISITOR_HPP
#define GCC_VISITOR_HPP


class ConstantExpr;
class FunctionStmt;
class ReturnStmt;
class ProgramAST;

class Visitor {
public:
    virtual ~Visitor() = default;

    virtual void visit(ConstantExpr&) = 0;
    virtual void visit(FunctionStmt&) = 0;
    virtual void visit(ReturnStmt&) = 0;
    virtual void visit(ProgramAST&) = 0;
};

#endif //GCC_VISITOR_HPP
