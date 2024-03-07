#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<vector<int> > data_parser() {
    vector<vector<int> > data;
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
        vector<int> elements;
        while (getline(ss, item, ',')) {
            elements.push_back(stoi(item));
        }
        data.push_back(elements);
    }
    return data;
}
