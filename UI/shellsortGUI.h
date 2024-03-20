//
// Created by Kuba on 17/03/2024.
//

#include <iostream>

#ifndef AIZO_SHELLSORTGUI_H
#define AIZO_SHELLSORTGUI_H

using namespace std;

void shellSortGUI(int repeat, string type, int temp,int pattern){
    ShellSort s1;
    DataGenerator d1;

    int progressSave = 0;

    ofstream outputFile("../data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    cout << "Quick sort: "<< repeat << " " << type << " "<< temp << " "<< pattern<<  endl;

    double time_table[repeat];
    float progress = 0.0;
    for(int x = 0; x < repeat; x++){
        if(type == "int"){
            vector<int> generatedData = d1.generateVector<int>(repeat, temp);
            if(repeat <= 30){
                for(int x = 0; x< generatedData.size(); x++ )cout << generatedData[x] <<  " ";
                cout << endl;
            }
            auto start = chrono::high_resolution_clock::now();
            switch (pattern) {
                case 1:{
                    s1.shellSort_1(&generatedData,generatedData.size());
                    break;
                }
                case 2:{
                    s1.shellSort_2(&generatedData, generatedData.size());
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
            switch (pattern) {
                case 1:{
                    s1.shellSort_1(&generatedData,generatedData.size());
                    break;
                }
                case 2:{
                    s1.shellSort_2(&generatedData, generatedData.size());
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
    string s = "../data/ShellSort" + to_string(repeat) + type + to_string(pattern)+to_string(temp) + ".txt";
    fs.open (s, std::fstream::in | std::fstream::out | std::fstream::app);
    for (int x = 0; x < repeat; x++)
    {
        sum += time_table[x];
        fs << time_table[x] << endl;
    }
    fs.close();
    outputFile << repeat << " -> " << sum/ repeat << endl << "s " << temp << "%";
    cout << endl;
    cout << sum / repeat << endl;
    outputFile.close();
}

#endif //AIZO_SHELLSORTGUI_H
