cmake_minimum_required(VERSION 3.4.3)
project(rpc-performance-test)

# Adds options to the compilation of source files
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH}) # To allow CMake to locate our Find*.cmake files

add_compile_options(-Wall -Wno-unused-variable -Wpointer-arith -Werror)
add_compile_options(-O2)

add_subdirectory(thrift)
add_subdirectory(zeromq)
add_subdirectory(grpc)