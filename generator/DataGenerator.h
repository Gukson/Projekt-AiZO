//
// Created by Kuba on 12/03/2024.
//

#include <iostream>
#include <vector>

using namespace std;

class DataGenerator {
    private:
        vector<int > amount;
        vector<int > percent;
        string paths;
    public:
        void generate();
        explicit DataGenerator(vector<int> data, vector<int> percents, string path);
};