cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

add_definitions(-std=c++11)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(AiZO)
add_executable(
        main main.cpp
        sorting_algorithms/heap_sort/Heapsort.tpp
        sorting_algorithms/shell_sort/shellsortGUI.tpp
        sorting_algorithms/shell_sort/ShellSort.h
        sorting_algorithms/quick_sort/QuickSort.tpp
        sorting_algorithms/quick_sort/QuickSort.h
        sorting_algorithms/quick_sort/QuickSort.h
        data/parsers/float_parser.h
        data/parsers/float_parser.h
        UI/GUI.tpp
        UI/GUI.h
        generator/DataGenerator.tpp
        generator/DataGenerator.h
        tester.h
        UI/testHeapSort.h
        UI/testQuickSort.h
        UI/testShellSort.h
        UI/testEverything.h
        sorting_algorithms/insert_sort/InsertSort.tpp
        sorting_algorithms/insert_sort/insert_sort.h
        UI/testInserSort.h

)