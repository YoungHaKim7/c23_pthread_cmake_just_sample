cmake_minimum_required(VERSION 3.10)
project(codelldb_debug_project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)

add_executable(codelldb_debug_project ${SOURCE_FILES})