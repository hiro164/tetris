cmake_minimum_required(VERSION 3.13)
project(test_cmake CXX)
include_directories(
 include
)
# add_executable(tetris src/original.cpp)
add_executable(tetris src/main.cpp src/tetris.cpp)

