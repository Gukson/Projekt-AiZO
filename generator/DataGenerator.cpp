//
// Created by Kuba on 12/03/2024.
//

#include "DataGenerator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <sstream>

using namespace std;
void DataGenerator::generate(vector<int> data, vector<int> percents, string path){
    ofstream outputFile("/Users/kuba/Documents/MojeDokumenty/studia/IV semestr/Projekt AiZO/data/" + paths);

    if (!outputFile.is_open()) {
        cerr << "Failed to open the file!" << std::endl;
        return;
    }

    for(int x = 0; x < amount.size(); x++){
        vector<int> data;

        int sorted = amount[x] * percent[x] / 100;
        for(int i = 0; i < sorted; i++){
            data.push_back(i);
        }

        int minRange = 1;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribution(minRange + sorted, amount[x]);

        for (int i = 0; i < amount[x] - sorted; ++i) {
            int randomNumber = distribution(gen);
            data.push_back(randomNumber);
        }

        stringstream ss;
        for(int i =0;i<data.size();i++)
        { if(i != 0)
            { ss<<",";
            }
            ss<< data[i];
        }
        outputFile << ss.str()<<endl;
    }

    cout << "Ukończono tworzenie pliku" << endl;
}
template<typename T>
vector<T> DataGenerator::generateVector(int size, int percents) {
    vector<T> data;
    int sorted = size * percents / 100;
    for(int i = 0; i < sorted; i++){
        data.push_back(i);
    }

    int minRange = 1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(minRange + sorted, size);
    for (int i = 0; i < size - sorted; ++i) {
        int randomNumber = distribution(gen);
        data.push_back(randomNumber);
    }

    return data;
}