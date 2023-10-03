// C++ code to linearly search x in arr[]. If x is present then return its location, otherwise return -1

#include <iostream>
using namespace std;

int search(int arr[],
		int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			return i;
	return -1;
}

// Main
int main(void)
{
	int arr[] = {4, 8, 10, 12, 14};
  
	// 'x' is the number that we are going to search in the array 'arr'
  int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);

	// Function call
	int result = search(arr, n, x);
	(result == -1) ?
	cout << "Element is not present in array" :
	cout << "Element is present at index " <<
			result;
	return 0;
}
