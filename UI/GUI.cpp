//
// Created by Kuba on 12/03/2024.
//

#include "GUI.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include "../generator/DataGenerator.h"

using namespace std;

void GUI::mainMenu() {
    int wybor;
    string path;

    vector<int> values;
    vector<int> percents;
    while(true){
        system("CLS");
        cout << "1. Generuj dane" << endl;
        cout << "3. Testuj HeapSort" << endl;
        cout << "4. Testuj QuickSort" << endl;
        cout << "5. Testuj ShellSort" << endl;
        cout << "6. Testuj wszystko" << endl;
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
                DataGenerator d1(values,percents,path);
                d1.generate();
                break;
            }
            case 2:{

                break;
            }
        }
    }

}
