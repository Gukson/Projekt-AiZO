//
// Created by Kuba on 27/03/2024.
//

#include <iostream>
#include <vector>

using namespace std;

#ifndef AIZO_INSERT_SORT_H
#define AIZO_INSERT_SORT_H


class InsertSort {
    public:
        template<typename T>
        static void insertionSort(vector<T> data, int n);
};
#include "InsertSort.tpp"


#endif //AIZO_INSERT_SORT_H
