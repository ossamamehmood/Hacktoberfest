#include <vector>

using namespace std;

// BUBBLE SORT
//------------------------------------------------------- 
// ------------ sorting in ascending order 
void bubbleSort(vector <int> &v, int n) {
	int i = 0;

	for(int i=0;i<n-1;i++{ 
		
		for (int j = 0; j < n-i-1 ; j++) { // unordered part
			
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]); 
			}
		}
	}
	    
}
	   


