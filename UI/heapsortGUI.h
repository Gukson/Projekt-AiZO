#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

#ifndef DODATKOWE_FUNKCJE_H
#define DODATKOWE_FUNKCJE_H

void heapSortGUI(int repeat, string type, int temp){
    double time_table[repeat];
    HeapSort h1;
    DataGenerator d1;

    int progressSave = 0;
    float progress = 0.0;

    ofstream outputFile("../data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    cout << "Heap sort: "<< repeat << " " << type << " "<< temp << endl;

    for(int x = 0; x < repeat; x++){

        if(type == "int"){

            vector<int> generatedData = d1.generateVector<int>(repeat, temp);
            auto start = chrono::high_resolution_clock::now();
            h1.heapSort(generatedData, generatedData.size());
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[x] = ms_double.count() / 1000;

        }
        if(type == "float"){

            vector<float> generatedData = DataGenerator::generateVector<float>(repeat, temp);
            auto start = chrono::high_resolution_clock::now();
            h1.heapSort(generatedData,generatedData.size());
            auto finish = chrono::high_resolution_clock::now();
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[x] = ms_double.count() / 1000;

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
    string s = "../data/HeapSort_" + to_string(repeat) + type + to_string(temp) + ".txt";
    fs.open (s, std::fstream::in | std::fstream::out | std::fstream::app);

    for (int x = 0; x < repeat; x++)
    {
        sum += time_table[x];
        fs << time_table[x] << endl;
    }
    fs.close();
    outputFile << repeat << " -> " << sum/ repeat  << "s " << temp << "%" << endl;
    cout << sum / repeat << endl;
    outputFile.close();

}

#endif





