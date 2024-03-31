//
// Created by Kuba on 12/03/2024.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <sstream>


using namespace std;

vector<vector<int>> DataGenerator::generateVector_int(int size) {
    vector<vector<int>> data;

    vector<int> temp;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(1, size);
    //w pełni losowa
    for (int i = 0; i < size; i++) {
        int randomNumber = distribution(gen);
        temp.push_back(randomNumber);
    }
    data.push_back(temp);
    //w 33% losowy
    for (int i = 0; i < size / 3; i++) {
        auto min = min_element(temp.begin() + i + 1, temp.end());
        int minimum = *min;
        for (int x = i + 1; x < temp.size(); x++) {
            if (temp[x] == minimum) {
                swap(temp[i], temp[x]);
                break;
            }
        }
    }
    data.push_back(temp);
    //w 66% losowy
    for (int i = (size/3) -2; i < (size / 3)*2; i++) {
        auto min = min_element(temp.begin() + i + 1, temp.end());
        int minimum = *min;
        for (int x = i + 1; x < temp.size(); x++) {
            if (temp[x] == minimum) {
                swap(temp[i], temp[x]);
                break;
            }
        }
    }
    data.push_back(temp);

    return data;
}

vector<vector<float> > DataGenerator::generateVector_float(int size) {
    vector<vector<float>> data;

    vector<float> temp;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> distribution(1.0, float(size) * 33 / 100);
    for (int i = 0; i < size; i++) {
        int randomNumber = distribution(gen);
        temp.push_back(randomNumber);
    }
    data.push_back(temp);
    //w 33% losowy
    for (int i = 0; i < size / 3; i++) {
        auto min = min_element(temp.begin() + i + 1, temp.end());
        float minimum = *min;
        for (int x = i + 1; x < temp.size(); x++) {
            if (temp[x] == minimum) {
                swap(temp[i], temp[x]);
                break;
            }
        }
    }
    data.push_back(temp);
    //w 66% losowy
    for (int i = (size/3) -2; i < (size / 3)*2; i++) {
        auto min = min_element(temp.begin() + i + 1, temp.end());
        float minimum = *min;
        for (int x = i + 1; x < temp.size(); x++) {
            if (temp[x] == minimum) {
                swap(temp[i], temp[x]);
                break;
            }
        }
    }
    data.push_back(temp);
    return data;
}