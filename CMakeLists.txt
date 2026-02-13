cmake_minimum_required(VERSION 4.1)
project(gcc C)

set(CMAKE_C_STANDARD 23)

add_executable(gcc src/main.c
        src/scanner.c
        src/scanner.h)
