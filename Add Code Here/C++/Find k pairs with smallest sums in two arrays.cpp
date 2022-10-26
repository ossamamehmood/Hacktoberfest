// C++ program to prints first k pairs with least sum from two
// arrays.
#include<bits/stdc++.h>

using namespace std;

// Function to find k pairs with least sum such
// that one element of a pair is from arr1[] and
// other element is from arr2[]
void kSmallestPair(int arr1[], int n1, int arr2[],
								int n2, int k)
{
	if (k > n1*n2)
	{
		cout << "k pairs don't exist";
		return ;
	}

	// Stores current index in arr2[] for
	// every element of arr1[]. Initially
	// all values are considered 0.
	// Here current index is the index before
	// which all elements are considered as
	// part of output.
	int index2[n1];
	memset(index2, 0, sizeof(index2));

	while (k > 0)
	{
		// Initialize current pair sum as infinite
		int min_sum = INT_MAX;
		int min_index = 0;

		// To pick next pair, traverse for all elements
		// of arr1[], for every element, find corresponding
		// current element in arr2[] and pick minimum of
		// all formed pairs.
		for (int i1 = 0; i1 < n1; i1++)
		{
			// Check if current element of arr1[] plus
			// element of array2 to be used gives minimum
			// sum
			if (index2[i1] < n2 &&
				arr1[i1] + arr2[index2[i1]] < min_sum)
			{
				// Update index that gives minimum
				min_index = i1;

				// update minimum sum
				min_sum = arr1[i1] + arr2[index2[i1]];
			}
		}

		cout << "(" << arr1[min_index] << ", "
			<< arr2[index2[min_index]] << ") ";

		index2[min_index]++;

		k--;
	}
}

// Driver code
int main()
{
	int arr1[] = {1, 3, 11};
	int n1 = sizeof(arr1) / sizeof(arr1[0]);

	int arr2[] = {2, 4, 8};
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	int k = 4;
	kSmallestPair( arr1, n1, arr2, n2, k);

	return 0;
}
