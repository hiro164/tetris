cmake_minimum_required(VERSION 3.10)
project(tetris CXX)
include_directories(
 include
)
add_executable(tetris src/main.cpp src/tetris.cpp)

