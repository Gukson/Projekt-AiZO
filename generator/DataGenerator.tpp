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
    uniform_int_distribution<int> distribution(1, size * 33 / 100);
    for (int i = 0; i < size/3; ++i) {
        int randomNumber = distribution(gen);
        temp.push_back(randomNumber);
    }
    distribution = uniform_int_distribution<int>(size * 33/ 100,size * 66/100);
    for(int i = 0; i < size/3; i++){
        int randomNumber = distribution(gen);
        temp.push_back(randomNumber);
    }
    distribution = uniform_int_distribution<int>(size * 66/ 100,size);
    for(int i = 0; i < size/3; i++){
        int randomNumber = distribution(gen);
        temp.push_back(randomNumber);
    }
    data.push_back(temp);

    for(int x = 0; x < size/3;x++){
        temp[x] = x;
    }
    data.push_back(temp);

    for(int x = 0; x < size * 2 / 3; x++){
        temp[x] = x;
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
    for (int i = 0; i < size/3; ++i) {
        float randomNumber = distribution(gen);
        temp.push_back(randomNumber);
    }
    distribution = uniform_real_distribution<float>(float(size) * 33/ 100,float(size) * 66/100);
    for(int i = 0; i < size/3; i++){
        float randomNumber = distribution(gen);
        temp.push_back(randomNumber);
    }
    distribution = uniform_real_distribution<float>(float(size) * 66/ 100,float(size));
    for(int i = 0; i < size/3; i++){
        float randomNumber = distribution(gen);
        temp.push_back(randomNumber);
    }
    data.push_back(temp);

    for(int x = 0; x < size/3;x++){
        temp[x] = float(x);
    }
    data.push_back(temp);

    for(int x = 0; x < size * 2 / 3; x++){
        temp[x] = float(x);
    }
    data.push_back(temp);
    return data;
}