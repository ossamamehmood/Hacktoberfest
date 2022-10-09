#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

    i = 0; 
	j = 0; 
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void printArr(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void mergeSort(int arr[], int low, int high)
{
	if (low < high) {

		int mid = low + (high - low) / 2;

		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
        printArr(arr,9);
	}
}

int main()
{
	int arr[] = { 5, 13, 2, 25, 7, 17, 20, 8, 4};
	printf("\nUnsorted Array : \n");
    printArr(arr,9);
    printf("\n");

	mergeSort(arr, 0, 8);

	printf("\nSorted array : \n");
	printArr(arr,9);
	return 0;
}
