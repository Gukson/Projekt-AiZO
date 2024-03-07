#include <iostream>
#include <vector>

using namespace std;

class HeapSort{
    
        vector<vector<int> > data;
    public:
        HeapSort(vector<vector<int> >);
        void heapSort(vector<int> data, int n);
        void build_max_heap(vector<int> &arr);
        void heap_sort(vector<int> data, int n);
        void max_heapify(std::vector<int> &arr, int i, int size_);
        void testHeapSort(int repeat);
};