//
// Created by Kuba on 08/03/2024.
//

#include "QuickSort.h"
#include <iostream>
#include <vector>
#include <fstream>


QuickSort::QuickSort(vector<vector<int>> arrdata) {
    quickSortData = arrdata;
    cout << quickSortData.size();
}

void QuickSort::quickSort(int (*func)(vector<int>*, int, int), vector<int> *arr, int left, int right) {
    if(left >= right) return;
    int border = partitionArray(func, arr, left, right);
    quickSort(func, arr, left, border-1);
    quickSort(func, arr, border+1, right);
}

int QuickSort::partitionArray(int (*pivotGenerator)(vector<int>*, int, int), vector<int> *arr, int left, int right) {
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

int QuickSort::chooseLeftPivot(vector<int> *arr, int left, int right) {//działą
    int pivotValue = (*arr)[left];
    swap((*arr)[left], (*arr)[right]);
    return pivotValue;
}

int QuickSort::chooseCentralPivot(vector<int> *arr, int left, int right) {
    int mid = left + (right - left) / 2;
    int pivotValue = (*arr)[mid];
    swap((*arr)[mid], (*arr)[right]);
    return pivotValue;
}

int QuickSort::chooseRandomPivot(vector<int> *arr, int left, int right) {//działa
    int index = left + ( rand() % ( right - left + 1 ) );
    int pivotValue = (*arr)[index];
    swap((*arr)[index], (*arr)[right]);
    return pivotValue;
}

int QuickSort::chooseRightPivot(vector<int> *arr, int left, int right) { //działa
    return (*arr)[right];
}

void QuickSort::testQuickSort(int repeat) {
    ofstream outputFile("/Users/kuba/Documents/MojeDokumenty/studia/IV semestr/Projekt AiZO/data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    outputFile << "Quick Sort" << endl << endl;


    double time_table[repeat];
    //right pivot
    outputFile << "right pivot" << endl;
    for (int x = 0; x < quickSortData.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<int> duplicateVector(quickSortData[x].begin(), quickSortData[x].end());
            auto start = chrono::high_resolution_clock::now();
            quickSort(QuickSort::chooseRightPivot, &duplicateVector, 0, duplicateVector.size() - 1);
            auto finish = chrono::high_resolution_clock::now();
            auto ms_int = chrono::duration_cast<chrono::milliseconds>(finish - start);
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[y] = ms_double.count() / 1000;
        }

        double sum = 0;
        for (int x = 0; x < repeat; x++)
        {
            sum += time_table[x];
        }

        outputFile << quickSortData[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << endl;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << sum << " seconds" << endl;
    }


    outputFile << "central pivot" << endl;
    for (int x = 0; x < quickSortData.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<int> duplicateVector(quickSortData[x].begin(), quickSortData[x].end());
            auto start = chrono::high_resolution_clock::now();
            quickSort(QuickSort::chooseCentralPivot, &duplicateVector, 0, duplicateVector.size() - 1);
            auto finish = chrono::high_resolution_clock::now();
            auto ms_int = chrono::duration_cast<chrono::milliseconds>(finish - start);
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[y] = ms_double.count() / 1000;
        }

        double sum = 0;
        for (int x = 0; x < repeat; x++)
        {
            sum += time_table[x];
        }

        outputFile << quickSortData[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << " seconds" << std::endl;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << sum << " seconds" << endl;
    }

    outputFile << "left pivot" << endl;
    for (int x = 0; x < quickSortData.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<int> duplicateVector(quickSortData[x].begin(), quickSortData[x].end());
            auto start = chrono::high_resolution_clock::now();
            quickSort(QuickSort::chooseLeftPivot, &duplicateVector, 0, duplicateVector.size() - 1);
            auto finish = chrono::high_resolution_clock::now();
            auto ms_int = chrono::duration_cast<chrono::milliseconds>(finish - start);
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[y] = ms_double.count() / 1000;
        }

        double sum = 0;
        for (int x = 0; x < repeat; x++)
        {
            sum += time_table[x];
        }

        outputFile << quickSortData[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << endl;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << " seconds" << std::endl;
    }

    outputFile << "random pivot" << endl;
    for (int x = 0; x < quickSortData.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<int> duplicateVector(quickSortData[x].begin(), quickSortData[x].end());
            auto start = chrono::high_resolution_clock::now();
            quickSort(QuickSort::chooseRandomPivot, &duplicateVector, 0, duplicateVector.size() - 1);
            auto finish = chrono::high_resolution_clock::now();
            auto ms_int = chrono::duration_cast<chrono::milliseconds>(finish - start);
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[y] = ms_double.count() / 1000;
        }

        double sum = 0;
        for (int x = 0; x < repeat; x++)
        {
            sum += time_table[x];
        }

        outputFile << quickSortData[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << " seconds" << std::endl;;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << sum << " seconds" << endl;
    }

    outputFile.close();
}



