cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(AiZO)
add_executable(main main.cpp
        sorting_algorithms/heap_sort/HeapSort.cpp
        sorting_algorithms/shell_sort/ShellSort.cpp
        sorting_algorithms/shell_sort/ShellSort.h
        sorting_algorithms/quick_sort/QuickSort.cpp
        sorting_algorithms/quick_sort/QuickSort.h
        sorting_algorithms/quick_sort/QuickSort.h
        data/parsers/float_parser.h
        data/parsers/float_parser.h
        data/generator/DataGenerator.cpp
        data/generator/DataGenerator.h
)