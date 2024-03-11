//
// Created by Kuba on 11/03/2024.
//

#include "DataGenerator.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <random>
#include <sstream>
#include <string>

using namespace std;

void DataGenerator::generateData(vector<int> amount, string fileName, int percent) {
    ofstream outputFile("/Users/kuba/Documents/MojeDokumenty/studia/IV semestr/Projekt AiZO/data/"+fileName);

    if (!outputFile.is_open()) {
        cerr << "Failed to open the file!" << std::endl;
        return;
    }

    for(int x = 0; x < amount.size(); x++){
        vector<int> data;

        int sorted = amount[x] * percent / 100;
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
