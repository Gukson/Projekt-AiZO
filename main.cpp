#include <iostream>
#include "data_parser.h"
#include <vector>
#include "tester.h"
#include "./sorting_algorithms/insertion_sort.h"
#include "./sorting_algorithms/heap_sort.h"
#include "./sorting_algorithms/shell_sort.h"
#include "heap_sort/heap_sort.h"

using namespace std;

int main()
{
     vector<int> myVector;
     myVector.push_back(9);
     myVector.push_back(2);
     myVector.push_back(6);
     myVector.push_back(5);
     myVector.push_back(4);
     myVector.push_back(3);
     myVector.push_back(1);
     myVector.push_back(7);
     myVector.push_back(8);
    // shell_sort(myVector, myVector.size());

    // ofstream outputFile("./data/output.txt", ofstream::out | ofstream::trunc);
    // outputFile.close();
    
    vector<vector<int> > data = data_parser();
    cout << "siema";

    // for (int x = 0; x < 3; x++)
    // {
    //     Tester(&insertionSort, 20, data[x]);
    //     cout << "completed chapter" << endl;
    // }
    
    // for (int x = 0; x < data.size(); x++)
    // {
    //     Tester(&heap_sort, 20, data[x]);
    //     cout << "completed chapter" << endl;
    // }

    HeapSort h1(data);
    h1.testHeapSort(20);
};