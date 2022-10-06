#include <vector>

using namespace std;

// QUICKSORT
// -------------------------------------------------------------------------

// Partition function
int partition(vector <int> &v, int start, int end) {
	
	int pivot = start; // Take the first element as a pivot 
	int i = start + 1;
	int j = end;

	while (i <= j) {
		
		// If element at the left is bigger than the pivot and
		// element at the right is smaller, swap elements
		
		if (v[i] > v[pivot] && v[j] < v[pivot]) {
			swap(v[i], v[j]);
		}
		else if (v[i] <= v[pivot]) { i++; } 
		else if (v[j] >= v[pivot]) { j--; } 
	}

	// we swap the pivot into the right position
	swap(v[j], v[pivot]);
	return j;
}

// QuickSort
void quickSort(vector <int> &v, int start, int end) {

	if (start < end) {
		int pivot = partition(v, start, end);
		quickSort(v, start, pivot);
		quickSort(v, pivot + 1, end);
	}
}

