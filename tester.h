#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;
using namespace std::chrono;

void Tester(void (*func)(vector<int>, int), int repeat, vector<int> data)
{
    double time_table[repeat];

    for (int x = 0; x < repeat; x++)
    {
        vector<int> duplicateVector(data.begin(), data.end());
        auto start = chrono::high_resolution_clock::now();
        func(duplicateVector, duplicateVector.size());
        auto finish = high_resolution_clock::now();
        auto ms_int = duration_cast<milliseconds>(finish - start);
        duration<double, std::milli> ms_double = finish - start;
        time_table[x] = ms_double.count() / 1000;
    }

    double sum = 0;
    for (int x = 0; x < repeat; x++){
        sum += time_table[x];
    }
    
    ofstream outputFile("./data/output.txt", ios_base::app);
    if (outputFile.is_open())
    {
        outputFile << data.size();
        outputFile << " -> ";
        outputFile << sum / repeat << endl;
        cout << "Time taken: " << sum/repeat << " seconds" << std::endl;
    }
}