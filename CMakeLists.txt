cmake_minimum_required(VERSION 3.11)
project(rpc-performance-test)

# Adds options to the compilation of source files
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH}) # To allow CMake to locate our Find*.cmake files
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_compile_options(-Wall -Wno-unused-variable -Wpointer-arith)
add_compile_options(-O2)

add_subdirectory(thrift)
add_subdirectory(zeromq)
add_subdirectory(grpc)