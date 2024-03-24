//
// Created by Kuba on 23/03/2024.
//
#include <iostream>


#ifndef didatkowyQuickSort_H
#define didatkowyQuickSort_H


using namespace std;

void testQuickSort(){
    int repeat;
    cout << "Podaj ilość powtórzeń algorytmu: ";
    cin >> repeat;

    string type;
    cout << "wybierz typ danych do testowania (int, float): ";
    cin >> type;

    int choose;
    cout<< "Wybierz rodzaj pivotu: " << endl << "1. Left" << endl << "2. Central" << endl << "3. Right" << endl << "4. Random" << endl;
    cin >> choose;

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
    QuickSort q1;
    if(type == "int"){
        outputFile << "Quick Sort - int" << endl << endl;
        for(int x = 0; x< repeat; x++){
            vector<vector<int>> generatedData = DataGenerator::generateVector_int(repeat);
            for(int y = 0; y < 3; y++){
                if(generatedData[y].size() <= 30){
                    for(int x = 0; x< generatedData[y].size(); x++ )cout << generatedData[y][x] <<  " ";
                    cout << endl;
                }
                switch (choose) {
                    case 1:{
                        auto start = chrono::high_resolution_clock::now();
                        q1.quickSort(QuickSort::chooseLeftPivot,&generatedData[y],0,generatedData[y].size()-1);
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                        break;
                    }
                    case 2: {
                        auto start = chrono::high_resolution_clock::now();
                        q1.quickSort(QuickSort::chooseCentralPivot,&generatedData[y],0,generatedData[y].size()-1);
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                    }
                    case 3:{
                        auto start = chrono::high_resolution_clock::now();
                        q1.quickSort(QuickSort::chooseRightPivot,&generatedData[y],0,generatedData[y].size()-1);
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                    }
                    case 4:{
                        auto start = chrono::high_resolution_clock::now();
                        q1.quickSort(QuickSort::chooseRandomPivot,&generatedData[y],0,generatedData[y].size()-1);
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
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
        outputFile << "Quick Sort - float" << endl << endl;
        for(int x = 0; x< repeat; x++){
            vector<vector<float>> generatedData = DataGenerator::generateVector_float(repeat);
            for(int y = 0; y < 3; y++){
                if(generatedData[y].size() <= 30){
                    for(int x = 0; x< generatedData[y].size(); x++ )cout << generatedData[y][x] <<  " ";
                    cout << endl;
                }
                switch (choose) {
                    case 1:{
                        auto start = chrono::high_resolution_clock::now();
                        q1.quickSort(QuickSort::chooseLeftPivot,&generatedData[y],0,generatedData[y].size()-1);
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                        break;
                    }
                    case 2: {
                        auto start = chrono::high_resolution_clock::now();
                        q1.quickSort(QuickSort::chooseCentralPivot,&generatedData[y],0,generatedData[y].size()-1);
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                    }
                    case 3:{
                        auto start = chrono::high_resolution_clock::now();
                        q1.quickSort(QuickSort::chooseRightPivot,&generatedData[y],0,generatedData[y].size()-1);
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
                    }
                    case 4:{
                        auto start = chrono::high_resolution_clock::now();
                        q1.quickSort(QuickSort::chooseRandomPivot,&generatedData[y],0,generatedData[y].size()-1);
                        auto finish = chrono::high_resolution_clock::now();
                        chrono::duration<double, std::milli> ms_double = finish - start;
                        time_table[y].push_back( ms_double.count());
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


    cout << "wprowadź dowolną cyfrę, aby kontynuować: ";
    cin >> sum;
}

#endif