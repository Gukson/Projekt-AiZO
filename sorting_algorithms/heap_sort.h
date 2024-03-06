#include <iostream>
#include <vector>
using namespace std;

void generowanie_kopca(vector<int> arr, int N, int i)
{

	int largest = i;

    //wzory na dzieci danego rodzica
	int l = 2 * i + 1; 

	int r = 2 * i + 2;

	if (l < N && arr[l] > arr[largest])
		largest = l;

	if (r < N && arr[r] > arr[largest])
		largest = r;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		generowanie_kopca(arr, N, largest);
	}
}

void heapSort(vector<int> arr, int N)
{
    //generowanie pierwszego kopc
	for (int i = N / 2 - 1; i >= 0; i--)
		generowanie_kopca(arr, N, i);

	for (int i = N - 1; i > 0; i--) { //zamiana ostatniego elementu tablicy z pierwszym (korzeniem) i ponowne generowanie kopca

		swap(arr[0], arr[i]);

		generowanie_kopca(arr, i, 0);
	}
}
