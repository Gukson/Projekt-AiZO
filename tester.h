#include <iostream>
#include <vector>
#include <chrono>

using namespace std::chrono;

void Tester(void (*func)(vector<int>, int), int repeat, vector<int> data)
{
    auto start = high_resolution_clock::now();
    
    for (int x = 0; x < repeat; x++)
    {
        vector<int> duplicateVector(data.begin(), data.end());
        func(duplicateVector, duplicateVector.size());
    }
    // write to file
    auto finish = high_resolution_clock::now();
    auto ms_int = duration_cast<milliseconds>(finish - start);
    duration<double, std::milli> ms_double = finish - start;


    cout << "Time taken: " << ms_double.count()/1000 << " seconds" << std::endl;
    ofstream outputFile("./data/output.txt", ios_base::app);
    if (outputFile.is_open()) {
        outputFile << repeat << endl;
        outputFile << ms_double.count()/(1000 * repeat) << endl;
    }
    outputFile.close();
}