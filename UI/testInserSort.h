//
// Created by Kuba on 27/03/2024.
//

#include <iostream>
#include <fstream>
#include <vector>

#ifndef AIZO_TESTINSERSORT_H
#define AIZO_TESTINSERSORT_H

using namespace std;

void testInsertSort(){
    int repeat;
    cout << "Podaj ilość powtórzeń algorytmu: ";
    cin >> repeat;

    string type;
    cout << "wybierz typ danych do testowania (int, float): ";
    cin >> type;

    ofstream outputFile("../data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    InsertSort i1;

    vector<vector<double> > time_table;
    vector<double> temp;
    time_table.push_back(temp);
    time_table.push_back(temp);
    time_table.push_back(temp);
    if(type == "int"){
        outputFile << "Insert Sort - int" << endl << endl;
        for(int x = 0; x< repeat; x++){
            vector<vector<int>> generatedData = DataGenerator::generateVector_int(repeat);
            for(int y = 0; y < 3; y++){
                auto start = chrono::high_resolution_clock::now();
                i1.insertionSort(generatedData[y], generatedData[y].size());
                auto finish = chrono::high_resolution_clock::now();
                chrono::duration<double, std::milli> ms_double = finish - start;
                time_table[y].push_back( ms_double.count());
            }
        }
    } else if(type == "float"){
        outputFile << "Insert Sort - float" << endl << endl;
        for(int x = 0; x< repeat; x++){
            vector<vector<float>> generatedData = DataGenerator::generateVector_float(repeat);
            for(int y = 0; y < 3; y++){
                auto start = chrono::high_resolution_clock::now();
                i1.insertionSort(generatedData[y], generatedData[y].size());
                auto finish = chrono::high_resolution_clock::now();
                chrono::duration<double, std::milli> ms_double = finish - start;
                time_table[y].push_back( ms_double.count());
            }
        }
    }
    double sum = 0;
    for (int x = 0; x < 3; x++)
    {
        for(int y = 0; y < time_table[x].size(); y++){
            sum += time_table[x][y];
        }
        outputFile << repeat << " -> " << sum/ repeat * 1000  << "s " << x*33 << "%" << endl;
        cout << sum / repeat << endl;

    }
    outputFile.close();


    cout << "wprowadź dowolną cyfrę, aby kontynuować: ";
    cin >> sum;
}

#endif //AIZO_TESTINSERSORT_H
