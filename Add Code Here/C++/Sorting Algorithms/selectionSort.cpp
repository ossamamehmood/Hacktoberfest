#include <vector>

using namespace std;

// SELECTION SORT
//------------------------------------------------------- 

void selectionSort(vector <int> &v, int n) {
	int minPosition, aux;

	for (int i = 0; i < n - 1; i++) {
		minPosition = i; // suppose "i" is the minimum

		for (int j = i + 1; j < n; j++) { // find the "min" element in the unsorted part
			
			if (v[j] < v[minPosition]) { 
				minPosition = j;
			}
		}
		//  swap the found "min" element to the sorted part
		if (minPosition > i) { 
			swap(v[minPosition], v[i]);
		}
	}

}
