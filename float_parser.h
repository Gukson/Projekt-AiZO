#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<vector<float> > data_parser_float() {
    vector<vector<float> > data;
    vector<string> strings;
    string line;
    ifstream file("/Users/kuba/Documents/MojeDokumenty/studia/IV semestr/Projekt AiZO/data/input.txt");
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return data;
    }
    while (getline(file, line)) {
        strings.push_back(line);
    }
    file.close();
    for (string s : strings) {
        stringstream ss(s);
        string item;
        vector<float> elements;
        while (getline(ss, item, ',')) {
            elements.push_back(stof(item));
        }
        data.push_back(elements);
    }
    return data;
}
