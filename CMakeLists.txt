cmake_minimum_required(VERSION 3.29)
project(peach_compiler C)

set(CMAKE_C_STANDARD 11)

add_executable(peach_compiler main.c
        compiler.c
        compiler.h
        cprocess.c
        helpers/vector.c
        helpers/vector.h
        helpers/buffer.c
        helpers/buffer.h
        test.c
        lex_process.c
        lexer.c
)
