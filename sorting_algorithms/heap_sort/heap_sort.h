#include <iostream>
#include <vector>

using namespace std;

class HeapSort{
    public:
        template<typename T>
        static void heapSort(vector<T> data, int n);
        template<typename T>
        static void build_max_heap(vector<T> &arr);
        template<typename T>
        static void max_heapify(vector<T> &arr, int i, int size);
};
#include "Heapsort.tpp"
