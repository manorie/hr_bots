cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_CPPCHECK "cppcheck")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(CMAKE_BUILD_TYPE Debug)
project(game)

add_executable(
  game
  main.cpp
  board.cpp
)
