#include <iostream>
#include "data_parser.h"
#include <vector>
#include "tester.h"
#include "./sorting_algorithms/insertion_sort.h"
#include "./sorting_algorithms/heap_sort.h"

using namespace std;

int main()
{
    vector<int> vect;
    vect.push_back(10);
    vect.push_back(20);
    vect.push_back(30);
    vect.push_back(25);
    vect.push_back(8);
    vect.push_back(13);
    vect.push_back(24);
    
    heapSort(vect, vect.size());

    // ofstream outputFile("./data/output.txt", ofstream::out | ofstream::trunc);
    // outputFile.close();
    // vector<vector<int> > data = data_parser();

    // for (int x = 0; x< data.size(); x++ ){
    //     Tester(&insertionSort, 100, data[x]);
    //     cout << "completed chapter" << endl;
    // }
};