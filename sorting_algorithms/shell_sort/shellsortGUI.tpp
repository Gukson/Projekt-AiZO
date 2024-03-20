//
// Created by Kuba on 07/03/2024.
//

#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <chrono>

using namespace std;


template<typename T>
void ShellSort::shellSort_1(vector<T> *arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = (*arr)[i];
            int j;
            for (j = i; j >= gap && (*arr)[j - gap] > temp; j -= gap)
                (*arr)[j] = (*arr)[j - gap];
            (*arr)[j] = temp;
        }
    }
}
template<typename T>
void ShellSort::shellSort_2(vector<T> *arr, int n) { //gap = 2^k - 1
    int j;
    for (int increment = pow(2, (int)( log(n)/log(2) ) )-1 ; increment > 0; increment /= 2) {
        for (int i = increment; i < n; i++) {
            int tmp = (*arr)[i];
            for (j = i; j >= increment; j -= increment) {
                if (tmp < (*arr)[j - increment]) {
                    (*arr)[j] = (*arr)[j - increment];
                } else {
                    break;
                }
            }
            (*arr)[j] = tmp;
        }
    }
}


