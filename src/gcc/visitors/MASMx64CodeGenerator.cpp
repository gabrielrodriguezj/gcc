
#include "gcc/visitors/MASMx64CodeGenerator.hpp"

#include "gcc/ast/ConstantExpr.hpp"
#include "gcc/ast/FunctionStmt.hpp"
#include "gcc/ast/ProgramAST.hpp"
#include "gcc/ast/ReturnStmt.hpp"

MASMx64CodeGenerator::MASMx64CodeGenerator(std::ostream& out, SourceManager& sourceManager): out_(out), sourceManager_(sourceManager) {

}

void MASMx64CodeGenerator::generate(ProgramAST& program) {
    // emit header of masm file
    emitHeader();

    // visit the program node
    program.accept(*this);

    //emit the footer of masm file
    emitFooter();
}

void MASMx64CodeGenerator::visit(ConstantExpr& expr) {
    emitLineIndented("mov eax, " + std::string(sourceManager_.lexeme(expr.getValue())) );

    /*
     * RAX for x64 is equivalent to EAX for x86 architecture.
     *
     * +---------------------------------------------------------------+
     * |                           RAX (64 bits)                       |
     * +-------------------------------+-------------------------------+
     *                                 |        EAX (32 bits)          |
     *                                 +---------------+---------------+
     *                                                 |     AX        |
     *                                                 +-------+-------+
     *                                                         | AH |AL|
     *                                                         +---+---+
     *
     * Or even, On x64 you can still use EAX.
     */
}

void MASMx64CodeGenerator::visit(FunctionStmt& stmt) {
    auto function = std::string(sourceManager_.lexeme(stmt.getName()));

    emitLine(function + " PROC");

    stmt.getBody().accept(*this);

    emitLine(function + " ENDP\n");
}

void MASMx64CodeGenerator::visit(ReturnStmt& stmt) {
    stmt.getExpression().accept(*this);
    emitLineIndented("ret");
}

void MASMx64CodeGenerator::visit(ProgramAST& stmt) {
    stmt.getFunction().accept(*this);
}

/*
 * For the next methods:
 * It is recommended to maintain \n: Writing text files line by line using
 * std::endl slows down the compilation or generation process, as it
 * forces the hard drive to work on each line instead of by blocks.
 */
void MASMx64CodeGenerator::emitHeader() {
    emitLine("option casemap:none\n");
    emitLine("PUBLIC main\n");
    emitLine(".CODE");

    /*
     * "option casemap:none" tells MASM not to change the case of
     * identifiers. In other words, it makes the assembler case-sensitive.
     *
     * Without "option casemap:none", MASM internally converts all
     * identifiers to uppercase.
     */
}

void MASMx64CodeGenerator::emitFooter() const {
    emitLine("END");
}

void MASMx64CodeGenerator::emitLine(const std::string& line) const {
    out_ << line << '\n';
}

void MASMx64CodeGenerator::emitLineIndented(const std::string& line) const {
    out_ << "    " << line << '\n';
}

