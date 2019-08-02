cmake_minimum_required(VERSION 3.14)
project(sudokoProject C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -pedantic-errors")
add_executable(sudokoProject main.c parser.c parser.h game.c game.h solver.c solver.h dataStructures.c dataStructures.h)