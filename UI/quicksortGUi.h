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

    ofstream outputFile("../data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    double time_table[repeat];
    for(int x = 0; x < repeat; x++){

        if(type == "int"){
            vector<int> generatedData = d1.generateVector<int>(repeat, temp);
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
        }
        if(type == "float"){

            vector<float> generatedData = d1.generateVector<float>(repeat, temp);
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
    cout << "wprowadź dowolną cyfrę, aby kontynuować: ";
    cin >> temp;

}

#endif //AIZO_QUICKSORTGUI_H
