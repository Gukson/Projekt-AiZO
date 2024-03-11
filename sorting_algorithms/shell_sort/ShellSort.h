//
// Created by Kuba on 07/03/2024.
//
#include <iostream>
#include <vector>

using namespace std;



class ShellSort {
    private:
    vector<vector<int> > data;
    vector<vector<float> > data_float;

    public:
        ShellSort(vector<vector<int> > data, vector<vector<float> > float_data);
        void shellSort_1_int(vector<int> arr, int n);
        void shellSort_2_int(vector<int> data, int n);
        void shellSort_1_float(vector<float> arr, float n);
        void shellSort_2_float(vector<float> data, float n);
        void testShellSort(int repeat);
};



