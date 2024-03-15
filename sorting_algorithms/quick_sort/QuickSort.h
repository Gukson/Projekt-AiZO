//
// Created by Kuba on 08/03/2024.
//
#include <iostream>
#include <vector>

using namespace std;

class QuickSort {
    private:
    vector<vector<int> > quickSortData;

    public:
        QuickSort(vector<vector<int> > data);
        int partitionArray(int (*func)(vector<int>*, int left, int right),vector<int> *arr, int left, int right);
        static int chooseLeftPivot(vector<int> *arr, int left, int right);
        static int chooseRightPivot(vector<int> *arr, int left, int right);
        static int chooseCentralPivot(vector<int> *arr, int left, int right);
        static int chooseRandomPivot(vector<int> *arr, int left, int right);
        void quickSort(int (*func)(vector<int> *arr, int left, int right),vector<int> *arr, int left, int right);
        void testQuickSort(int repeat, int (*pivotChooser) (vector<int> *arr, int left, int right), string pivotKind);
        void run(int repeat);
};