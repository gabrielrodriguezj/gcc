cmake_minimum_required(VERSION 4.2)
project(gcc)

set(CMAKE_CXX_STANDARD 26)

include_directories(include)

add_executable(gcc apps/compiler/main.cpp
        src/gcc/lexer/Lexer.cpp)
