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
    ofstream outputFile("../data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

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
        cout << x << endl;
    }
    double sum = 0;
    for (int x = 0; x < repeat; x++)
    {
        sum += time_table[x];
    }
    outputFile << repeat << " -> " << sum/ repeat << endl;
    cout << sum / repeat;
    outputFile.close();
    cout << "wprowadź dowolną cyfreę, aby kontynuować: ";
    cin >> temp;
}

#endif





