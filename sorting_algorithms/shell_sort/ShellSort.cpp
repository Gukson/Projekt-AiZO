//
// Created by Kuba on 07/03/2024.
//

#include "ShellSort.h"
#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <math.h>

using namespace std;


ShellSort::ShellSort(vector<vector<int> > rdata, vector<vector<float> > float_data) {
    data = std::move(rdata);
    data_float = float_data;
};



void ShellSort::shellSort_1_int(vector<int> arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void ShellSort::shellSort_2_int(vector<int> arr, int n) { //gap = 2^k - 1
    int j;
    for (int increment = pow(2, (int)( log(n)/log(2) ) )-1 ; increment > 0; increment /= 2) {
        for (int i = increment; i < n; i++) {
            int tmp = arr[i];
            for (j = i; j >= increment; j -= increment) {
                if (tmp < arr[j - increment]) {
                    arr[j] = arr[j - increment];
                } else {
                    break;
                }
            }
            arr[j] = tmp;
        }
    }
}
void ShellSort::shellSort_1_float(vector<float> arr, float n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i += 1) {
            float temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}

void ShellSort::shellSort_2_float(vector<float> arr, float n) { //gap = 2^k - 1
    int j;
    for (int increment = pow(2, static_cast<int>(log(n) / log(2))) - 1; increment > 0; increment /= 2) {
        for (int i = increment; i < n; i++) {
            float tmp = arr[i];
            for (j = i; j >= increment; j -= increment) {
                if (tmp < arr[j - increment]) {
                    arr[j] = arr[j - increment];
                } else {
                    break;
                }
            }
            arr[j] = tmp;
        }
    }
}


void ShellSort::testShellSort(int repeat) {
    ofstream outputFile("/Users/kuba/Documents/MojeDokumenty/studia/IV semestr/Projekt AiZO/data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    outputFile << "Shell Sort" << endl << endl;
    outputFile << "Shell method - basic - int" << endl;
    double time_table[repeat];

    for (int x = 0; x < data.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<int> duplicateVector(data[x].begin(), data[x].end());
            auto start = chrono::high_resolution_clock::now();
            shellSort_1_int(duplicateVector, duplicateVector.size());
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

        outputFile << data[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << endl;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << sum << " seconds" << endl;
    }

    outputFile << "Hibbard method - int" << endl;

    for (int x = 0; x < data.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<int> duplicateVector(data[x].begin(), data[x].end());
            auto start = chrono::high_resolution_clock::now();
            shellSort_2_int(duplicateVector, duplicateVector.size());
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

        outputFile << data[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << endl;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << sum << " seconds" << endl;
    }


    outputFile << "Shell method - basic - float" << endl;

    for (int x = 0; x < data_float.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<float> duplicateVector(data_float[x].begin(), data_float[x].end());
            auto start = chrono::high_resolution_clock::now();
            shellSort_1_float(duplicateVector, duplicateVector.size());
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

        outputFile << data[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << endl;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << sum << " seconds" << endl;
    }

    outputFile << "Hibbard method - float" << endl;

    for (int x = 0; x < data_float.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<float> duplicateVector(data_float[x].begin(), data_float[x].end());
            auto start = chrono::high_resolution_clock::now();
            shellSort_2_float(duplicateVector, duplicateVector.size());
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

        outputFile << data[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << endl;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << sum << " seconds" << endl;
    }


    outputFile.close();
}

