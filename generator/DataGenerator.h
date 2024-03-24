//
// Created by Kuba on 12/03/2024.
//

#include <iostream>
#include <vector>

using namespace std;

class DataGenerator {
    public:
        static vector<vector<int> > generateVector_int(int);
        static vector<vector<float> > generateVector_float(int);
};

#include "DataGenerator.tpp"