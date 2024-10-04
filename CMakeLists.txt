cmake_minimum_required(VERSION 3.29)
project(is_os_tp1 C)

set(CMAKE_C_STANDARD 11)

add_executable(is_os_tp1 main.c
        memory.h
        memory.c
        main.h
        projection.h
        projection.c)

target_compile_options(is_os_tp1 PRIVATE -Wall -Wextra)