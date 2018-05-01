cmake_minimum_required(VERSION 3.10)
project(Algorithm-With-C)

set(CMAKE_CXX_STANDARD 11)

add_executable(Algorithm main.cpp SortTestHelper.h Sort.h SortHelper.h)
