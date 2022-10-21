// C program to merge two max heaps.
#include <stdio.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// Standard heapify function to heapify a
// subtree rooted under idx. It assumes
// that subtrees of node are already heapified.
void maxHeapify(int arr[], int N, int idx)
{
	// Find largest of node and its children
	if (idx >= N)
		return;

	int l = 2 * idx + 1;
	int r = 2 * idx + 2;
	int max = idx;
	if (l < N && arr[l] > arr[idx])
		max = l;
	if (r < N && arr[r] > arr[max])
		max = r;

	// Put maximum value at root and
	// recur for the child with the
	// maximum value
	if (max != idx) {
		swap(&arr[max], &arr[idx]);
		maxHeapify(arr, N, max);
	}
}

// Builds a max heap of given arr[0..n-1]
void buildMaxHeap(int arr[], int N)
{
	// building the heap from first non-leaf
	// node by calling max heapify function
	for (int i = N / 2 - 1; i >= 0; i--)
		maxHeapify(arr, N, i);
}

// Merges max heaps a[] and b[] into merged[]
void mergeHeaps(int merged[], int a[], int b[], int N,
				int M)
{
	// Copy elements of a[] and b[] one by one
	// to merged[]
	for (int i = 0; i < N; i++)
		merged[i] = a[i];
	for (int i = 0; i < M; i++)
		merged[N + i] = b[i];

	// build heap for the modified array of
	// size n+m
	buildMaxHeap(merged, N + M);
}

// Driver's code
int main()
{
	int a[] = { 10, 5, 6, 2 };
	int b[] = { 12, 7, 9 };

	int N = sizeof(a) / sizeof(a[0]);
	int M = sizeof(b) / sizeof(b[0]);

	int merged[N + M];

	// Function call
	mergeHeaps(merged, a, b, N, M);

	for (int i = 0; i < N + M; i++)
		printf("%d ", merged[i]);

	return 0;
}
