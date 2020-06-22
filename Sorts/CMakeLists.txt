cmake_minimum_required(VERSION 3.14)
project(Sorts)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sorts main.cpp SelectionSort.h Student.h SortTestHelper.h InsertionSort.h BubbleSort.h ShellSort.h)