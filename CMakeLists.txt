cmake_minimum_required(VERSION 2.8)
project(Brainfuck)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(src)

file(GLOB_RECURSE SRC_LIST RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp src/*.h)
add_executable(brainfuck ${SRC_LIST})
