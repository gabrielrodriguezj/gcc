cmake_minimum_required(VERSION 4.1)
project(gcc)

set(CMAKE_CXX_STANDARD 26)

add_executable(gcc src/main.cpp
        src/scanner.cpp
        src/scanner.h
        src/core/token/TokenKind.h
        src/core/token/Token.h
        src/core/exception/ScannerException.cpp
        src/core/exception/ScannerException.h
        src/core/token/TokenUtil.h)
