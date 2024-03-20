//
// Created by Kuba on 07/03/2024.
//
#include <iostream>
#include <vector>

using namespace std;

class ShellSort {
    public:
        template<typename T>
        static void shellSort_1(vector<T> *arr, int n);
        template<typename T>
        static void shellSort_2(vector<T> *arr, int n);
};

#include "shellsortGUI.tpp"