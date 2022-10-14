#include <vector>

using namespace std;

// INSERTION SORT
//------------------------------------------------------------

void insertionSort(vector <int> &v, int n) {
	int current, pos;

	for (int i = 1; i < n; i++) {
		current = v[i]; 
		pos = i; // limit of the ordered part, pos not included

		// we make space
		while (pos > 0 && v[pos - 1] > current) {
			v[pos] = v[pos - 1]; 
			pos--;
		}
		
		// we move the current value to its position 
		if (pos != i)  
			v[pos] = current; 
	}
}

