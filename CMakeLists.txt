cmake_minimum_required(VERSION 4.2)
project(gcc)

set(CMAKE_CXX_STANDARD 26)

include_directories(include)

add_executable(gcc apps/compiler/main.cpp
        src/gcc/lexer/Lexer.cpp
        src/gcc/parser/Parser.cpp
        src/gcc/ast/ProgramAST.cpp
        src/gcc/ast/FunctionStmt.cpp
        src/gcc/ast/ConstantExpr.cpp
        src/gcc/ast/ReturnStmt.cpp
        src/gcc/visitors/AstPrinter.cpp
        src/gcc/source/SourceManager.cpp
        src/gcc/visitors/MASMx86CodeGenerator.cpp
        src/gcc/visitors/MASMx64CodeGenerator.cpp
        src/gcc/driver/CompilerDriver.cpp
        src/gcc/pipeline/Pipeline.cpp
        src/gcc/driver/CommandLineParser.cpp
        src/gcc/driver/CompilerContext.cpp
        src/gcc/pipeline/LexerPass.cpp
        src/gcc/pipeline/ParserPass.cpp
        src/gcc/ast/UnaryExpr.cpp
        src/gcc/diagnostics/DiagnosticEngine.cpp
        src/gcc/diagnostics/consumers/ConsoleDiagnosticConsumer.cpp
        src/gcc/diagnostics/formatters/PlainDiagnosticFormatter.cpp
)
