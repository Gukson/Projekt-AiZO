//
// Created by Kuba on 12/03/2024.
//

#include <iostream>
#include <string>
#include <fstream>
#include "../generator/DataGenerator.h"
#include "../data/parsers/data_parser.h"
#include "../data/parsers/float_parser.h"
#include "../sorting_algorithms/heap_sort/heap_sort.h"
#include "../sorting_algorithms/quick_sort/QuickSort.h"
#include "../sorting_algorithms/shell_sort/ShellSort.h"
#include "heapsortGUI.h"
#include "quicksortGUi.h"
#include "shellsortGUI.h"
#include "GUI.h"


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

                ofstream outputFile("../data/output.txt", std::ios_base::app);
                if (!outputFile.is_open()) {
                    cerr << "Error opening file." << endl;
                    return;
                }
                if(type == "int"){
                    outputFile << "Heap Sort - int" << endl << endl;
                } else if(type == "float"){
                    outputFile << "Heap Sort - float" << endl << endl;
                }
                outputFile.close();

                heapSortGUI(repeat, type, temp);
                cout << "wprowadź dowolną cyfreę, aby kontynuować: ";
                cin >> temp;
                break;
            }
            case 3:{
                int repeat;
                cout << "Podaj ilość powtórzeń algorytmu: ";
                cin >> repeat;

                string type;
                cout << "wybierz typ danych do testowania (int, float): ";
                cin >> type;

                cout << "podaj jaki procent danych ma być posortowany w momoencie generowania danych: ";
                int temp;
                cin >> temp;

                cout << "Jaki pivot wybrać? " << endl << "1. Lewy\n" << "2. Centralny\n" << "3. Prawy\n" << "4. Losowy\n";
                int pivotWybor;
                cin >> pivotWybor;

                ofstream outputFile("../data/output.txt", std::ios_base::app);
                if (!outputFile.is_open()) {
                    cerr << "Error opening file." << endl;
                    return;
                }
                if(type == "int"){
                    outputFile << "Quick Sort - int" << endl << endl;
                } else if(type == "float"){
                    outputFile << "Quick Sort - float" << endl << endl;
                }
                outputFile.close();

                quicksortGUI(repeat,type,temp,pivotWybor);
                cout << "wprowadź dowolną cyfreę, aby kontynuować: ";
                cin >> temp;
                break;
            }
            case 4:{
                int repeat;
                cout << "Podaj ilość powtórzeń algorytmu: ";
                cin >> repeat;

                string type;
                cout << "wybierz typ danych do testowania (int, float): ";
                cin >> type;

                cout << "podaj jaki procent danych ma być posortowany w momoencie generowania danych: ";
                int temp;
                cin >> temp;

                cout << "Jaki pivot wybrać? " << endl << "1. Basic\n" << "2. Hibbard\n";
                int pattern;
                cin >> pattern;

                ofstream outputFile("../data/output.txt", std::ios_base::app);
                if (!outputFile.is_open()) {
                    cerr << "Error opening file." << endl;
                    return;
                }
                if(type == "int"){
                    outputFile << "Shell Sort - basic" << endl << endl;
                } else if(type == "float"){
                    outputFile << "Shell Sort - Hibbard" << endl << endl;
                }
                outputFile.close();

                shellSortGUI(repeat,type,temp,pattern);
                cout << "wprowadź dowolną cyfreę, aby kontynuować: ";
                cin >> temp;
                break;
            }
            case 5:{
                ofstream outputFile("../data/output.txt", std::ios_base::app);
                if (!outputFile.is_open()) {
                    cerr << "Error opening file." << endl;
                    return;
                }
                outputFile << "Heap Sort - int\n";
                outputFile.close();
                auto start = chrono::high_resolution_clock::now();

                vector<int> help;
                help.push_back(15000);


                for(int x = 0; x < help.size(); x++){
                    heapSortGUI(help[x],"int",0);
                    heapSortGUI(help[x],"int",33);
                    heapSortGUI(help[x],"int",66);
                }


                fstream fs;
                fs.open ("../data/output.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                fs << "Heap Sort - float\n";
                fs.close();
                for(int x = 0; x < help.size(); x++){
                    heapSortGUI(help[x],"float",0);
                    heapSortGUI(help[x],"float",33);
                    heapSortGUI(help[x],"float",66);
                }


                fs.open ("../data/output.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                fs << "Quick Sort - int\n";
                fs.close();


                for(int x = 0; x < help.size(); x++){
                    quicksortGUI(help[x],"int",0,1);
                    quicksortGUI(help[x],"int",0,2);
                    quicksortGUI(help[x],"int",0,3);
                    quicksortGUI(help[x],"int",0,4);

                    quicksortGUI(help[x],"int",33,1);
                    quicksortGUI(help[x],"int",33,2);
                    quicksortGUI(help[x],"int",33,3);
                    quicksortGUI(help[x],"int",33,4);

                    quicksortGUI(help[x],"int",66,1);
                    quicksortGUI(help[x],"int",66,2);
                    quicksortGUI(help[x],"int",66,3);
                    quicksortGUI(help[x],"int",66,4);
                }

                fs.open ("../data/output.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                fs << "Quick Sort - float\n";
                fs.close();


                for(int x = 0; x < help.size(); x++){
                    quicksortGUI(help[x],"float",0,1);
                    quicksortGUI(help[x],"float",0,2);
                    quicksortGUI(help[x],"float",0,3);
                    quicksortGUI(help[x],"float",0,4);

                    quicksortGUI(help[x],"float",33,1);
                    quicksortGUI(help[x],"float",33,2);
                    quicksortGUI(help[x],"float",33,3);
                    quicksortGUI(help[x],"float",33,4);

                    quicksortGUI(help[x],"float",66,1);
                    quicksortGUI(help[x],"float",66,2);
                    quicksortGUI(help[x],"float",66,3);
                    quicksortGUI(help[x],"float",66,4);
                }

                fs.open ("../data/output.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                fs << "Shell Sort - int\n";
                fs.close();


                for(int x = 0; x < help.size(); x++){
                    shellSortGUI(help[x],"int",0,1);
                    shellSortGUI(help[x],"int",33,1);
                    shellSortGUI(help[x],"int",66,1);


                    shellSortGUI(help[x],"int",0,2);
                    shellSortGUI(help[x],"int",33,2);
                    shellSortGUI(help[x],"int",66,2);
                }

                fs.open ("../data/output.txt", std::fstream::in | std::fstream::out | std::fstream::app);
                fs << "Shell Sort - float\n";
                fs.close();


                for(int x = 0; x < help.size(); x++){
                    shellSortGUI(help[x],"float",0,1);
                    shellSortGUI(help[x],"float",33,1);
                    shellSortGUI(help[x],"float",66,1);


                    shellSortGUI(help[x],"float",0,2);
                    shellSortGUI(help[x],"float",33,2);
                    shellSortGUI(help[x],"float",66,2);
                }


                auto finish = chrono::high_resolution_clock::now();
                chrono::duration<double, std::milli> ms_double = finish - start;
                cout << ms_double.count()*60000 << endl;

                break;
            }
        }
    }

}
