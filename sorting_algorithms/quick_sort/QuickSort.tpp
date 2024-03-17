//
// Created by Kuba on 08/03/2024.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

template<typename T>
void QuickSort::quickSort(T (*func)(vector<T>*, int, int), vector<T> *arr, int left, int right) {
    if(left >= right) return;
    int border = partitionArray(func, arr, left, right);
    quickSort(func, arr, left, border-1);
    quickSort(func, arr, border+1, right);
}
template<typename T>
int QuickSort::partitionArray(T (*pivotGenerator)(vector<T>*, int, int), vector<T> *arr, int left, int right) {
    int pivotValue = pivotGenerator(arr,left,right);
    int border = left - 1;
    int i = left;

    while(i < right){
        if((*arr)[i] < pivotValue){
            border++;
            if(border != i) swap((*arr)[border], (*arr)[i]);
        }
        i++;
    }
    border++;
    if(border != right){
        swap((*arr)[border], (*arr)[right]);
    }
    return border;
}

template<typename T>
T QuickSort::chooseLeftPivot(vector<T> *arr, int left, int right) {
    int pivotValue = (*arr)[left];
    swap((*arr)[left], (*arr)[right]);
    return pivotValue;
}
template<typename T>
T QuickSort::chooseCentralPivot(vector<T> *arr, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivotValue = (*arr)[mid];
    swap((*arr)[mid], (*arr)[right]);
    return pivotValue;
}
template<typename T>
T QuickSort::chooseRandomPivot(vector<T> *arr, int left, int right) {
    int index = left + ( rand() % ( right - left + 1 ) );
    int pivotValue = (*arr)[index];
    swap((*arr)[index], (*arr)[right]);
    return pivotValue;
}
template<typename T>
T QuickSort::chooseRightPivot(vector<T> *arr, int left, int right) {
    return (*arr)[right];
}