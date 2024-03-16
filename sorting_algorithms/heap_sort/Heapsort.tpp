#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

template<typename T>
void HeapSort::heapSort(vector<T> data, int n)
{
    build_max_heap(data);
    for (int i = data.size() - 1; i > 0; i--)
    {
        swap(data[0], data[i]);
        n--;
        max_heapify(data, 0, n);
    }
    if(n <= 30){
        for(int x = 0; x< data.size(); x++ )cout << data[x] <<  " ";
        cout << endl;
    }
    cout << endl;

};
template<typename T>
void HeapSort::build_max_heap(vector<T> &arr)
{
    for (int i = (arr.size() / 2); i >= 0; i--)
        max_heapify(arr, i, arr.size());
};
template<typename T>
void HeapSort::max_heapify(vector<T> &arr, int i, int size_)
{
    int largest,
            l = (2 * i) + 1,
            r = l + 1;

    if (l < size_ && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if (r < size_ && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size_);
    }
};
