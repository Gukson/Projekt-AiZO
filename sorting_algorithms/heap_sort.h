#include <iostream>
#include <vector>
using namespace std;

void max_heapify(std::vector<int>& arr, int i, int size_)
{
    int largest,
	l = (2*i) + 1, 
	r = l + 1;

    if(l < size_ && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r < size_ && arr[r] > arr[largest])
        largest = r;

    if(largest != i)
    {
        std::swap(arr[i], arr[largest]);
        max_heapify(arr, largest, size_);
    }
}

void build_max_heap(std::vector<int>& arr)
{
    for(int i = (arr.size() / 2); i >= 0; i--)
    max_heapify(arr, i, arr.size());
}

void heap_sort(vector<int> data, int n)
{
   build_max_heap(data);
   for(int i = data.size() - 1; i > 0; i--)
   {
        swap(data[0], data[i]);
        n--;
        max_heapify(data, 0, n);
    }
}