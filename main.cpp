#include <iostream>
#include "data/parsers/data_parser.h"
#include <vector>
#include "sorting_algorithms/heap_sort/heap_sort.h"
#include "sorting_algorithms/shell_sort/ShellSort.h"
#include "sorting_algorithms/quick_sort/QuickSort.h"
#include "data/parsers/float_parser.h"
#include "data/generator/DataGenerator.h"

using namespace std;

int main()
{
    ofstream outputFile("/Users/kuba/Documents/MojeDokumenty/studia/IV semestr/Projekt AiZO/data/output.txt");
    outputFile.close();
//    vector<vector<int> > data_int = data_parser();
//    vector<vector<float> >data_float = data_parser_float();
    vector<int> temp;
    temp.push_back(10);
    temp.push_back(20);

    DataGenerator d1;
    d1.generateData(temp,"test", 10);


//    vector <vector<int> > test;
//    vector<int> temp;
//
//    for (int i = 10; i >=0; i--) {
//        temp.push_back(i); // Dodawanie losowej liczby do wektora
//    }
//    test.push_back(temp);
//    cout << test.size() << endl;

//    auto start = chrono::high_resolution_clock::now();
//    HeapSort h1(data_int);
//    h1.testHeapSort(100);
//
//    ShellSort s1(data_int, data_float);
//    s1.testShellSort(100);

//    QuickSort q1(data_int);
//    q1.run();
//    auto finish = chrono::high_resolution_clock::now();
//    auto ms_int = chrono::duration_cast<chrono::milliseconds>(finish - start);
//    chrono::duration<double, std::milli> ms_double = finish - start;
//    cout << endl;
//    cout << "Całość zajęła: " << ms_double.count() / 60000 << " min";

};