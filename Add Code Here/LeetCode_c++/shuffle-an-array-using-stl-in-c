// C++ program to shuffle
// the given array
// using shuffle() method

#include <bits/stdc++.h>
using namespace std;

// Shuffle array
void shuffle_array(int arr[], int n)
{

	// To obtain a time-based seed
	unsigned seed = 0;

	// Shuffling our array
	shuffle(arr, arr + n,
			default_random_engine(seed));

	// Printing our array
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver code
int main()
{

	int a[] = { 10, 20, 30, 40 };

	int n = sizeof(a) / sizeof(a[0]);

	shuffle_array(a, n);

	return 0;
}
