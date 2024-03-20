//
// Created by Kuba on 17/03/2024.
//

#include <iostream>
#include <vector>
#include <chrono>

#ifndef AIZO_QUICKSORTGUI_H
#define AIZO_QUICKSORTGUI_H


void quicksortGUI(int repeat, string type, int temp,int pivotWybor){
    QuickSort q1;
    DataGenerator d1;

    int progressSave = 0;
    float progress = 0.0;

    ofstream outputFile("../data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    cout << "Quick sort: "<< repeat << " " << type << " "<< temp << " "<< pivotWybor<<  endl;

    double time_table[repeat];
    for(int x = 0; x < repeat; x++){


        if(type == "int"){
            vector<int> generatedData = d1.generateVector<int>(repeat, temp);
            if(repeat <= 30){
                for(int x = 0; x< generatedData.size(); x++ )cout << generatedData[x] <<  " ";
                cout << endl;
            }
            auto start = chrono::high_resolution_clock::now();
            switch (pivotWybor) {
                case 1:{
                    q1.quickSort(QuickSort::chooseLeftPivot,&generatedData,0,generatedData.size()-1);
                    break;
                }
                case 2:{
                    q1.quickSort(QuickSort::chooseCentralPivot,&generatedData,0,generatedData.size()-1);
                    break;
                }
                case 3:{
                    q1.quickSort(QuickSort::chooseRightPivot,&generatedData,0,generatedData.size()-1);
                    break;
                }
                case 4:{
                    q1.quickSort(QuickSort::chooseRandomPivot,&generatedData,0,generatedData.size()-1);
                    break;
                }
            }
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[x] = ms_double.count() / 1000;
            if(repeat <= 30){
                for(int x = 0; x< generatedData.size(); x++ )cout << generatedData[x] <<  " ";
                cout << endl;
                cout << endl;
            }
        }
        if(type == "float"){

            vector<float> generatedData = d1.generateVector<float>(repeat, temp);
            if(repeat <= 30){
                for(int x = 0; x< generatedData.size(); x++ )cout << generatedData[x] <<  " ";
                cout << endl;
            }
            auto start = chrono::high_resolution_clock::now();
            switch (pivotWybor) {
                case 1:{
                    q1.quickSort(QuickSort::chooseLeftPivot,&generatedData,0,generatedData.size()-1);
                    break;
                }
                case 2:{
                    q1.quickSort(QuickSort::chooseCentralPivot,&generatedData,0,generatedData.size()-1);
                    break;
                }
                case 3:{
                    q1.quickSort(QuickSort::chooseRightPivot,&generatedData,0,generatedData.size()-1);
                    break;
                }
                case 4:{
                    q1.quickSort(QuickSort::chooseRandomPivot,&generatedData,0,generatedData.size()-1);
                    break;
                }
            }
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[x] = ms_double.count() / 1000;
            if(repeat <= 30){
                for(int x = 0; x< generatedData.size(); x++ )cout << generatedData[x] <<  " ";
                cout << endl;
                cout << endl;
            }

        }
        int barWidth = 70;

        if ((int)progress - progressSave > 0 && repeat > 30){
            progressSave = (int)progress;
            std::cout << "\r" <<"[";
            int pos = barWidth * progress/100;
            for (int i = 0; i < barWidth; ++i) {
                if (i < pos) std::cout <<  "=";
                else if (i == pos) std::cout << ">";
                else std::cout  << " ";
            }
            std::cout << "] " << int(progress) << "%";
        }
        progress += float(100.0/repeat);
        cout.flush();
    }
    double sum = 0;
    fstream fs;
    string s = "../data/QuickSort" + to_string(repeat) + type + to_string(pivotWybor) +to_string(temp) + ".txt";
    fs.open (s, std::fstream::in | std::fstream::out | std::fstream::app);
    for (int x = 0; x < repeat; x++)
    {
        sum += time_table[x];
        fs << time_table[x] << endl;
    }
    fs.close();
    outputFile << repeat << " -> " << sum/ repeat << endl << "s " << temp << "% " << pivotWybor;
    cout << sum / repeat;
    outputFile.close();
}

#endif //AIZO_QUICKSORTGUI_H
