cmake_minimum_required(VERSION 3.17)
project(caEx1 C)

set(CMAKE_C_STANDARD 99)

set(PROJECT_HEADERS
        src/ex1.h
        )
set(PROJECT_SOURCES
        src/main.c
        src/ex1.c
        )

add_executable(caEx1 ${PROJECT_SOURCES} ${PROJECT_HEADERS})