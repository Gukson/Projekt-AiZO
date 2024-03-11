#include <iostream>
#include "heap_sort.h"
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;

void heapSort(vector<int> data, int n);
void build_max_heap(vector<int> &arr);
void heap_sort(vector<int> data, int n);
void max_heapify(std::vector<int> &arr, int i, int size_);
void testHeapSort(int repeat);

vector<vector<int> > data;

HeapSort::HeapSort(vector<vector<int> > rdata)
{
    data = rdata;
};

void HeapSort::heapSort(vector<int> data, int n)
{
    build_max_heap(data);
    for (int i = data.size() - 1; i > 0; i--)
    {
        swap(data[0], data[i]);
        n--;
        max_heapify(data, 0, n);
    }

};

void HeapSort::build_max_heap(std::vector<int> &arr)
{
    for (int i = (arr.size() / 2); i >= 0; i--)
        max_heapify(arr, i, arr.size());
};

void HeapSort::max_heapify(std::vector<int> &arr, int i, int size_)
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

void HeapSort::testHeapSort(int repeat)
{
    ofstream outputFile("/Users/kuba/Documents/MojeDokumenty/studia/IV semestr/Projekt AiZO/data/output.txt", std::ios_base::app);
    if (!outputFile.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    outputFile << "Heap Sort" << endl << endl;

    double time_table[repeat];

    for (int x = 0; x < data.size(); x++)
    {
        for (int y = 0; y < repeat; y++)
        {
            vector<int> duplicateVector(data[x].begin(), data[x].end());
            auto start = chrono::high_resolution_clock::now();
            heapSort(duplicateVector, duplicateVector.size());
            auto finish = chrono::high_resolution_clock::now();
            auto ms_int = chrono::duration_cast<chrono::milliseconds>(finish - start);
            chrono::duration<double, std::milli> ms_double = finish - start;
            time_table[y] = ms_double.count() / 1000;

        }

        double sum = 0;
        for (int x = 0; x < repeat; x++)
        {
            sum += time_table[x];
        }

        outputFile << data[x].size();
        outputFile << " -> ";
        outputFile << sum / repeat << endl;
        cout << "Avg Time taken: " << sum/repeat << " seconds" << std::endl;
        cout << "Time taken " << sum << " seconds" << endl;
    }

    outputFile.close();
}