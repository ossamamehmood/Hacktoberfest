#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int[], int);

void bubbleSort(int arr[], int size) {
	int i, j, temp;
	for(i = 0; i < size - 1; i++) {
		for(j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				//swap
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main() {
	int n, arr[100];
	int i;
	int op, cont;
	do {
	    
		printf("Enter size of array: ");
		scanf("%d", &n);
		printf("Enter values of array:\n");
		for(i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
		}
		printf("Enter sorting algorithm to use:\n1: Bubble\n");
		scanf("%d", &op);
		
		switch(op) {
			case 1:
				bubbleSort(arr, n);
				break;
			default:
				printf("Invalid option!");
		}
		for(i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\nContinue? 1/0:\t");
		scanf("%d", &cont);
	} while(cont == 1);
	
	return 0;
}
