//
// Created by Kuba on 24/03/2024.
//

#include <iostream>
#include <vector>
#include <fstream>

#ifndef AIZO_TESTEVERYTHING_H
#define AIZO_TESTEVERYTHING_H

using namespace std;

void testEverything(){
    ofstream outputFile("../data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    vector<int> repeat;
    repeat.push_back(5000);
    repeat.push_back(10000);
    repeat.push_back(15000);
    repeat.push_back(20000);
    vector<vector<double> > time_table;

    //int
    for(int i = 0; i < repeat.size(); i++){
        cout << "INT - " << repeat[i] <<endl;
        int progressSave = 0;
        float progress = 0.0;

        //0 - Heap Sort
        //1 - Quick Sort - Left pivot
        //2 - Quick Sort - Central pivot
        //3 - Quick Sort - Right pivot
        //5 - Quick Sort - Random pivot
        //6 - Shell Sort - Basic algo
        //7 - Shell Sort - Second algo
        for(int x = 0; x < 21;x++){
            vector<double> temp;
            time_table.push_back(temp);
        }
        for(int j = 0; j < repeat[i]; j++){
            vector<vector<int>> generatedData = DataGenerator::generateVector_int(repeat[i]);
            vector<int> duplicateVector;
            chrono::duration<double, std::milli> ms_double;
            int licznik = 0;
            auto start = chrono::high_resolution_clock::now();
            auto finish = chrono::high_resolution_clock::now();

            //Heap Sort
            for(int x =0; x< 3; x++){
                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                HeapSort::heapSort(duplicateVector, duplicateVector.size());
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;
            }

            //Quick Sort
            QuickSort q1;
            for(int x =0; x< 3; x++){
                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                q1.quickSort(QuickSort::chooseLeftPivot,&duplicateVector,0,duplicateVector.size()-1);
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;

                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                q1.quickSort(QuickSort::chooseCentralPivot,&duplicateVector,0,duplicateVector.size()-1);
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;

                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                q1.quickSort(QuickSort::chooseRightPivot,&duplicateVector,0,duplicateVector.size()-1);
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;

                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                q1.quickSort(QuickSort::chooseRandomPivot,&duplicateVector,0,duplicateVector.size()-1);
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;
            }

            ShellSort s1;
            for(int x =0; x< 3; x++){
                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                s1.shellSort_1(&duplicateVector,duplicateVector.size());
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;

                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                s1.shellSort_2(&duplicateVector,duplicateVector.size());
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;
            }


            int barWidth = 70;
            if ((int)progress - progressSave > 0){
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
            progress += float(100.0/repeat[i]);
            cout.flush();
        }
        double sum = 0;
        outputFile << "INT" << endl << endl;
        int l = 0;
        for(int x = 0; x < 3; x++){
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Heap sort - "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
        }

        for(int x = 0; x < 3; x++){
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Quick sort Left Pivot - "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Quick sort Central Pivot- "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Quick sort Right Pivot- "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Quick sort Random Pivot- "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
        }

        for(int x = 0; x < 3; x++){
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Shell sort Basic Algo - "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;

            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Shell sort Second Algo - "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
        }


        cout << endl;
    }





    //FLOAT

    for(int i = 0; i < repeat.size(); i++){
        cout << "FLOAT - " << repeat[i] <<endl;
        int progressSave = 0;
        float progress = 0.0;

        vector<vector<double> > time_table;
        //0 - Heap Sort
        //1 - Quick Sort - Left pivot
        //2 - Quick Sort - Central pivot
        //3 - Quick Sort - Right pivot
        //5 - Quick Sort - Random pivot
        //6 - Shell Sort - Basic algo
        //7 - Shell Sort - Second algo
        for(int x = 0; x < 21;x++){
            vector<double> temp;
            time_table.push_back(temp);
        }
        for(int j = 0; j < repeat[i]; j++){
            vector<vector<float>> generatedData = DataGenerator::generateVector_float(repeat[i]);
            vector<float> duplicateVector;
            chrono::duration<double, std::milli> ms_double;
            int licznik = 0;
            auto start = chrono::high_resolution_clock::now();
            auto finish = chrono::high_resolution_clock::now();

            //Heap Sort
            for(int x =0; x< 3; x++){
                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                HeapSort::heapSort(duplicateVector, duplicateVector.size());
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;
            }

            //Quick Sort
            QuickSort q1;
            for(int x =0; x< 3; x++){
                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                q1.quickSort(QuickSort::chooseLeftPivot,&duplicateVector,0,duplicateVector.size()-1);
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;

                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                q1.quickSort(QuickSort::chooseCentralPivot,&duplicateVector,0,duplicateVector.size()-1);
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;

                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                q1.quickSort(QuickSort::chooseRightPivot,&duplicateVector,0,duplicateVector.size()-1);
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;

                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                q1.quickSort(QuickSort::chooseRandomPivot,&duplicateVector,0,duplicateVector.size()-1);
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;
            }

            ShellSort s1;
            for(int x =0; x< 3; x++){
                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                s1.shellSort_1(&duplicateVector,duplicateVector.size());
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;

                duplicateVector.assign(generatedData[x].begin(), generatedData[x].end());
                start = chrono::high_resolution_clock::now();
                s1.shellSort_2(&duplicateVector,duplicateVector.size());
                finish = chrono::high_resolution_clock::now();
                ms_double = finish - start;
                time_table[licznik].push_back(ms_double.count());
                licznik++;
            }


            int barWidth = 70;
            if ((int)progress - progressSave > 0){
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
            progress += float(100.0/repeat[i]);
            cout.flush();
        }
        double sum = 0;
        outputFile << "FLOAT" << endl << endl;
        int l = 0;
        for(int x = 0; x < 3; x++){
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Heap sort - "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
        }

        for(int x = 0; x < 3; x++){
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Quick sort Left Pivot - "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Quick sort Central Pivot- "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Quick sort Right Pivot- "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Quick sort Random Pivot- "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
        }

        for(int x = 0; x < 3; x++){
            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Shell sort Basic Algo - "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;

            sum = 0;
            for(int y = 0; y < time_table[l].size(); y++){
                sum += time_table[l][y];
            }
            outputFile <<"Shell sort Second Algo - "<< repeat[i] << " -> " << sum/ repeat[i] * 1000  << "s " << x*33 << "%" << endl;
            l++;
        }
    }
    outputFile.close();

}

#endif //AIZO_TESTEVERYTHING_H
