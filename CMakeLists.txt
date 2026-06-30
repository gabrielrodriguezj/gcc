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
        src/gcc/visitors/MASMCodeGenerator.cpp
)
