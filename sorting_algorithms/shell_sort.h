#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void shell_sort(vector<int> arr, int N)
{
    for (int k = 1; true; k++)
    {
        int d = N / (pow(2, k)); //liczymy dystans
        for (int x = 0; x < N; x++)
        {
            if (x + d < N) 
            {
                if (arr[x + d] < arr[x]) // sprawdzamy czy jest moliwośc zamienienia miejscami liczb
                {
                    swap(arr[x], arr[x + d]);
                }
            }
            if (x - d >= 0)
            {
                int t = 1;
                while (x - d * t >= 0)
                {
                    if (arr[x - d * (t-1)] < arr[x - d * t])//cofamy się o dystans i sprawdzmay czy moemy pozamieniainne rzeczy miejscami
                    {
                        swap(arr[x - d * t], arr[x - d * (t-1)]);
                    }
                    t++;
                }
            }
        }

        if(d == 1)
            break;
    }
}