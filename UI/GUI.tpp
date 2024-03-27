//
// Created by Kuba on 12/03/2024.
//

#include <iostream>
#include <string>
#include <fstream>


#include "testHeapSort.h"
#include "testQuickSort.h"
#include "testShellSort.h"
#include "testEverything.h"
#include "testInserSort.h"
#include "GUI.h"

using namespace std;

void GUI::mainMenu() {
    int wybor;
    string path;

    vector<int> values;
    vector<int> percents;
    while(true){
        system("CLS");
        cout << "1. Testuj InsertSort" << endl;
        cout << "2. Testuj HeapSort" << endl;
        cout << "3. Testuj QuickSort" << endl;
        cout << "4. Testuj ShellSort" << endl;
        cout << "5. Testuj wszystko" << endl;
        cin >> wybor;
        switch (wybor) {
            case 1:{
                testInsertSort();
                break;
            }
            case 2:{
                testHeapSort();
                break;
            }
            case 3:{
                testQuickSort();
                break;
            }
            case 4:{
                testShellSort();
                break;
            }
            case 5:{
                testEverything();
                break;
            }
        }
    }

}
