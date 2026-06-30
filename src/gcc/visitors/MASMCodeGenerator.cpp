#include "gcc/visitors/MASMCodeGenerator.hpp"

#include "gcc/ast/ConstantExpr.hpp"
#include "gcc/ast/FunctionStmt.hpp"
#include "gcc/ast/ProgramAST.hpp"
#include "gcc/ast/ReturnStmt.hpp"
#include "gcc/source/SourceManager.hpp"

MASMCodeGenerator::MASMCodeGenerator(std::ostream& out, SourceManager& sourceManager): out_(out), sourceManager_(sourceManager) {

}

void MASMCodeGenerator::generate(ProgramAST& program) {
    // emit header of masm file
    emitHeader();

    // visit the program node
    program.accept(*this);

    //emit the footer of masm file
    emitFooter();
}

void MASMCodeGenerator::visit(ConstantExpr& expr) {
    emitLine("mov eax, " + std::string(sourceManager_.lexeme(expr.getValue())) );

    /*
     * Several x86 instructions are designed around EAX, arithmetic
     * operations, printf, and even return.
     *
     * EAX, along with ECX and EDX, are caller-saved registers. A function
     * can freely modify them. Compilers often prefer EAX as the primary
     * register for temporary results: it is intended for this use and
     * corresponds to the function's return register.
     *
     * A very common strategy is to define a simple rule:
     * - Every expression leaves its result in EAX. EBX and ECX are used
     * as auxiliary registers when an operation needs to store a temporary
     * value. If more temporary registers are needed, the stack (push/pop)
     * or a more advanced register allocator is used.
     * - This convention makes each visit() method independent: it doesn't
     * need to know who will use the result, only ensure that, upon
     * completion, the calculated value is in EAX.
     */
}

void MASMCodeGenerator::visit(FunctionStmt& stmt) {
    auto function = std::string(sourceManager_.lexeme(stmt.getName()));

    emitLine(function + " PROC\n");

    stmt.getBody().accept(*this);

    emitLine(function + " ENDP\n\n");
}

void MASMCodeGenerator::visit(ReturnStmt& stmt) {
    stmt.getExpression().accept(*this);
    emitLine("ret\n");
}

void MASMCodeGenerator::visit(ProgramAST& stmt) {
    stmt.getFunction().accept(*this);
}

/*
 * For the next methods:
 * It is recommended to maintain \n: Writing text files line by line using
 * std::endl slows down the compilation or generation process, as it
 * forces the hard drive to work on each line instead of by blocks.
 */
void MASMCodeGenerator::emitHeader() {
    out_ << ".386\n";
    out_ << ".model flat, stdcall\n";
    out_ << "option casemap:none\n\n";

    out_ << ".code\n\n";
}

void MASMCodeGenerator::emitFooter() const {
    out_ << "END\n";
}

void MASMCodeGenerator::emitLine(const std::string& line) {
    out_ << "    " << line << '\n';
}

