cmake_minimum_required(VERSION 3.25)
project(ComplexExample C)

set(CMAKE_C_STANDARD 11)

add_executable(ComplexExample main.c io.h io.c calculator.h calculator.c)
