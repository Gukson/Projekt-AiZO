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
        static void shellSort_1_int(vector<int> *arr, int n);
        static void shellSort_2_int(vector<int> *data, int n);
        static void shellSort_1_float(vector<float> *arr, float n);
        static void shellSort_2_float(vector<float> *data, float n);
        void testShellSort_int(int repeat, void (*methodChooser) (vector<int> *arr, int n), string methodKind);
        void testShellSort_float(int repeat, void (*methodChooser) (vector<float>*, float), string methodKind);
        void run(int repeat);
};



