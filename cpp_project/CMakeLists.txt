cmake_minimum_required(VERSION 3.29)
project(cpp_project)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_project main.cpp
        src/binOpStructs.hpp
        "src/binOpClass.hpp"
        src/Item.h
        src/Item.cpp)
