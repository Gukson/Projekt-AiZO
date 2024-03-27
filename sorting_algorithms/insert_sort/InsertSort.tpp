//
// Created by Kuba on 27/03/2024.
//

#include "insert_sort.h"
template<typename T>
void InsertSort::insertionSort(vector<T> data, int n) {
    if(data.size() <= 30){
        for(int x = 0; x< data.size(); x++ )cout << data[x] <<  " ";
        cout << endl;
    }
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = data[i];
        j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
    }
    if(data.size() <= 30){
        for(int x = 0; x< data.size(); x++ )cout << data[x] <<  " ";
        cout << endl;
        cout << endl;
    }
}