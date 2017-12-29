cmake_minimum_required(VERSION 3.8)
project(35)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        A/code.cpp
        B/code.cpp
        C/code.cpp
        D/code.cpp
        E/code.cpp
        F/code.cpp)

add_executable(35 ${SOURCE_FILES})