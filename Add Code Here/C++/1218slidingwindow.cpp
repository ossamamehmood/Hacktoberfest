// C program for the above approach
#include <stdio.h>

void printKMax(int arr[], int N, int K)
{
	int j, max;

	for (int i = 0; i <= N - K; i++) {
		max = arr[i];

		for (j = 1; j < K; j++) {
			if (arr[i + j] > max)
				max = arr[i + j];
		}
		printf("%d ", max);
	}
}

// Driver's Code
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int N = sizeof(arr) / sizeof(arr[0]);
	int K = 3;

	// Function call
	printKMax(arr, N, K);
	return 0;
}
