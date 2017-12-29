cmake_minimum_required(VERSION 3.8)
project(matrix_search)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        code.cpp)

add_executable(matrix_search ${SOURCE_FILES})