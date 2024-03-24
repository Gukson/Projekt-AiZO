//
// Created by Kuba on 24/03/2024.
//
#include <iostream>
#include <fstream>
#ifndef AIZO_TESTSHELLSORT_H
#define AIZO_TESTSHELLSORT_H

using namespace std;

void testShellSort(){
    int repeat;
    cout << "Podaj ilość powtórzeń algorytmu: ";
    cin >> repeat;

    string type;
    cout << "wybierz typ danych do testowania (int, float): ";
    cin >> type;

    cout << "Jaki rodzaj algorytmu wybrać? " << endl << "1. Basic\n" << "2. Hibbard\n";
    int pattern;
    cin >> pattern;

    ofstream outputFile("../data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    vector<vector<double> > time_table;
    vector<double> temp;
    time_table.push_back(temp);
    time_table.push_back(temp);
    time_table.push_back(temp);
    ShellSort s1;
    if(type == "int"){
        outputFile << "Shell Sort - int" << endl << endl;
        for(int x = 0; x< repeat; x++){
            vector<vector<int>> generatedData = DataGenerator::generateVector_int(repeat);

            for(int y = 0; y < 3; y++){
                if(generatedData[y].size() <= 30){
                    for(int x = 0; x< generatedData[y].size(); x++ )cout << generatedData[y][x] <<  " ";
                    cout << endl;
                }
                switch (pattern) {
                    case 1:{
                        auto start = chrono::high_resolution_clock::now();
                        s1.shellSort_1(&generatedData[y],generatedData.size());
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                        break;
                    }
                    case 2:{
                        auto start = chrono::high_resolution_clock::now();
                        s1.shellSort_2(&generatedData[y],generatedData.size());
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                        break;
                    }

                }
                if(generatedData[y].size() <= 30){
                    for(int x = 0; x< generatedData[y].size(); x++ )cout << generatedData[y][x] <<  " ";
                    cout << endl;
                    cout << endl;
                }
            }

        }

    } else if(type == "float"){
        outputFile << "Shell Sort - float" << endl << endl;
        for(int x = 0; x< repeat; x++){
            vector<vector<float>> generatedData = DataGenerator::generateVector_float(repeat);
            for(int y = 0; y < 3; y++){
                if(generatedData[y].size() <= 30){
                    for(int x = 0; x< generatedData[y].size(); x++ )cout << generatedData[y][x] <<  " ";
                    cout << endl;
                }
                switch (pattern) {
                    case 1:{
                        auto start = chrono::high_resolution_clock::now();
                        s1.shellSort_1(&generatedData[y],generatedData.size());
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                        break;
                    }
                    case 2:{
                        auto start = chrono::high_resolution_clock::now();
                        s1.shellSort_2(&generatedData[y],generatedData.size());
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                        break;
                    }
                }
                if(generatedData[y].size() <= 30){
                    for(int x = 0; x< generatedData[y].size(); x++ )cout << generatedData[y][x] <<  " ";
                    cout << endl;
                    cout << endl;
                }
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

    cout << "wprowadź dowolną cyfreę, aby kontynuować: ";
    cin >> sum;
}

#endif //AIZO_TESTSHELLSORT_H
