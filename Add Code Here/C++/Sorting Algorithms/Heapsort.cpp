// C++ program for implementation of Heap Sort

#include <iostream>
using namespace std;


void heapify(int arr[], int N, int i)
{

	
	int largest = i;

	// left = 2*i + 1
	int l = 2 * i + 1;

	// right = 2*i + 2
	int r = 2 * i + 2;

	// If left child is larger than root
	if (l < N && arr[l] > arr[largest])
		largest = l;


	if (r < N && arr[r] > arr[largest])
		largest = r;

	
	if (largest != i) {
		swap(arr[i], arr[largest]);

		
		heapify(arr, N, largest);
	}
}

void heapSort(int arr[], int N)
{


	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);


	for (int i = N - 1; i > 0; i--) {

	
		swap(arr[0], arr[i]);

	
		heapify(arr, i, 0);
	}
}


void printArray(int arr[], int N)
{
	for (int i = 0; i < N; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}


int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	// Function call
	heapSort(arr, N);

	cout << "Sorted array is \n";
	printArray(arr, N);
}
