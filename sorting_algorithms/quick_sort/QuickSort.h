//
// Created by Kuba on 08/03/2024.
//
#include <iostream>
#include <vector>

using namespace std;

class QuickSort {
    public:
        template<typename T>
        int partitionArray(T (*func)(vector<T>*, int left, int right),vector<T> *arr, int left, int right);
        template<typename T>
        static T chooseLeftPivot(vector<T> *arr, int left, int right);
        template<typename T>
        static T chooseRightPivot(vector<T> *arr, int left, int right);
        template<typename T>
        static T chooseCentralPivot(vector<T> *arr, int left, int right);
        template<typename T>
        static T chooseRandomPivot(vector<T> *arr, int left, int right);
        template<typename T>
        void quickSort(T (*func)(vector<T> *arr, int left, int right),vector<T> *arr, int left, int right);
};

#include "QuickSort.tpp"