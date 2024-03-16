//
// Created by Kuba on 12/03/2024.
//

#include "GUI.h"
#include <iostream>
#include <string>
#include "../generator/DataGenerator.h"
#include "../data/parsers/data_parser.h"
#include "../data/parsers/float_parser.h"
#include "../sorting_algorithms/heap_sort/heap_sort.h"
#include "../sorting_algorithms/quick_sort/QuickSort.h"
#include "../sorting_algorithms/shell_sort/ShellSort.h"

using namespace std;

void GUI::mainMenu() {
    int wybor;
    string path;

    vector<int> values;
    vector<int> percents;
    while(true){
        system("CLS");
        cout << "1. Generuj dane" << endl;
        cout << "2. Testuj HeapSort" << endl;
        cout << "3. Testuj QuickSort" << endl;
        cout << "4. Testuj ShellSort" << endl;
        cout << "5. Testuj wszystko" << endl;
        cin >> wybor;
        switch (wybor) {
            case 1:
            {
                system("CLS");
                cout << "Podaj nazwe pliku pod którą ma być zapisany plik (na koncu napisz .txt): ";
                cin >> path;
                cout << "Podawaj kolejno teraz w osobnych linijkach ilość danych oraz jaki procent z nich ma być już posortowana - aby zakonczyc wpisz 0" << endl;
                while (true){
                    cout << "Podaj ilosc: ";
                    int temp;
                    cin >> temp;
                    if(temp == 0) break;
                    values.push_back(temp);
                    cout << "Podaj procent (bez znaczku %): ";
                    cin >> temp;
                    percents.push_back(temp);
                }
                DataGenerator d1;
                d1.generate(values,percents,path);
                break;
            }
            case 2:{
                int repeat;
                cout << "Podaj ilość powtórzeń algorytmu: ";
                cin >> repeat;

                string type;
                cout << "wybierz typ danych do testowania (int, float): ";
                cin >> type;

                cout << "podaj jaki procent danych ma być posortowany w momoencie generowania danych: ";
                int temp;
                cin >> temp;

                DataGenerator g1;
                HeapSort h1;
                for(int x = 0; x < repeat; x++){
                    if(type == "int"){
                        vector<int> generatedData = DataGenerator::generateVector<int>(repeat, temp);
                        for(int x : generatedData)cout << x <<  " ";
                        cout << endl;
                        h1.heapSort(generatedData,generatedData.size());
                        for(int x = 0; x< generatedData.size(); x++ )cout << generatedData[x] <<  " ";
                        cout << endl;
                    }
                }

                break;
            }
            case 3:{
                cout << "Wybierz plik zawierający dane do testowania (np. data.txt)";
                string path;
                cin >> path;

                int repeat;
                cout << "Podaj ilość powtórzeń algorytmu: ";
                cin >> repeat;

                int temp;
                cout << "1. left pivot" << endl;
                cout << "2. central pivot" << endl;
                cout << "3. right pivot" << endl;
                cout << "4. random pivot" << endl;
                cout << "5. Wszystkie jeden po drugim" << endl;
                cout << "Wybierz którego pivota chcesz użyć: ";
                cin >> temp;


                vector<vector<int> > data = data_parser(path);
                QuickSort q1(data);
                switch (temp) {
                    case 1:{
                        q1.testQuickSort(repeat,q1.chooseLeftPivot,"Left pivot");
                        break;
                    }
                    case 2:{
                        q1.testQuickSort(repeat,q1.chooseCentralPivot,"Central pivot");
                        break;
                    }
                    case 3:{
                        q1.testQuickSort(repeat,q1.chooseRightPivot,"Right pivot");
                        break;
                    }
                    case 4:{
                        q1.testQuickSort(repeat,q1.chooseRandomPivot,"Random pivot");
                        break;
                    }
                    case 5:{
                        q1.run(repeat);
                    }
                }
                break;
            }
            case 4:{
                cout << "Wybierz plik zawierający dane do testowania (np. data.txt)";
                string path;
                cin >> path;
                vector<vector<int> > data = data_parser(path);
                vector<vector<float> > data_float = data_parser_float(path);

                int repeat;
                cout << "Podaj ilość powtórzeń algorytmu: ";
                cin >> repeat;
                cout << "1. Basic" << endl;
                cout << "2. Hibbard" << endl;
                cout << "Wybierz z jakiego wzoru na odstęp ma korzytsać algorytm: ";
                int temp;
                cin >> temp;
                ShellSort s1(data,data_float);
                switch (temp) {
                    case 1: {
                        cout << "Na jakim typie danych algorytm ma zostać przetestowany?" << endl;
                        cout << "1. int" << endl;
                        cout << "2. float" << endl;
                        int temp2;
                        cin >> temp2;
                        switch (temp2) {
                            case 1: {
                                s1.testShellSort_int(repeat,s1.shellSort_1_int,"Basic method - int");
                                break;
                            }
                            case 2: {
                                s1.testShellSort_float(repeat,s1.shellSort_1_float,"Basic method - float");
                                break;
                            }
                        }
                        break;
                    }
                    case 2:{
                        cout << "Na jakim typie danych algorytm ma zostać przetestowany?" << endl;
                        cout << "1. int" << endl;
                        cout << "2. float" << endl;
                        int temp2;
                        cin >> temp2;
                        switch (temp2) {
                            case 1: {
                                s1.testShellSort_int(repeat,s1.shellSort_2_int,"Hibbard method - int");
                                break;
                            }
                            case 2: {
                                s1.testShellSort_float(repeat,s1.shellSort_2_float,"Hibbard method - float");
                                break;
                            }
                        }
                        break;
                    }

                }
                break;
            }
            case 5:{
//                cout << "Wybierz plik zawierający dane do testowania (np. data.txt)";
//                string path;
//                cin >> path;
//
//                int repeat;
//                cout << "Podaj ilość powtórzeń algorytmu: ";
//                cin >> repeat;
//
//                vector<vector<int> > data = data_parser(path);
//                vector<vector<float> > data_float = data_parser_float(path);
//                auto start = chrono::high_resolution_clock::now();
//                HeapSort h1(data);
//                h1.testHeapSort(repeat);
//                QuickSort q1(data);
//                q1.run(repeat);
//                ShellSort s1(data,data_float);
//                s1.run(repeat);
//                auto finish = chrono::high_resolution_clock::now();
//                auto ms_int = chrono::duration_cast<chrono::milliseconds>(finish - start);
//                chrono::duration<double, std::milli> ms_double = finish - start;
//                cout << endl;
//                cout << "Całość zajęła: " << ms_double.count() / 60000 << " min";
                break;
            }
        }
    }

}
