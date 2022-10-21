#include "stdio.h"
#include "stdlib.h"

// Radix Sorting by Suman Roy
// HacktoberFest 2021

// Display list of numbers in the array
void showNumbers(int* numbers, int size){
    int i=0;
    while(i<size){
        printf("[%d] ",numbers[i]);
        i++;
    }
    printf("\n");
}

// Get the big number from the array
int getMaxValue(int* array, int size){
    int i=0,max=array[0];
    while(i<size){
        max = array[i]>max?array[i]:max;
        i++;
    }
    return max;
}


// start sorting
int* radixSort(int* array, int size){
	int i, j;
	int k = 0, n = 1, max, lsd;
    // creating a temporary bucket for holding the values
	int** temp = (int **)malloc(sizeof(int) * size);
	int* order;

	max = getMaxValue(array, size);
	for(i = 0; i < size; i++)
		temp[i] = (int *)calloc(size, sizeof(int));
	order = (int *)calloc(size, sizeof(int));
	while(n <= max){
		for(i = 0; i < size; i++){
			lsd = (array[i] / n) % 10;
			temp[lsd][order[lsd]] = array[i];
			order[lsd] += 1;
		}
		for(i = 0; i < size; i++){
			if(order[i] != 0){
				for(j = 0; j < order[i]; j++){
					array[k] = temp[i][j];
					k += 1;
				}
			}
			order[i] = 0;
		}
		n *= 10;
		k = 0;
	}
	return array;
}




void main(){
    printf("\n\nRadix Sorting\n");
    int arr[] = {275,128,28,249,433,91,288,12,29,179,248,479,487,42,153,191,132,323,205,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("\nSize of Array = %d\n",size);
    printf("Max value : %d",getMaxValue(arr, size));
    printf("\n\nContents of Array Before Sorting : \n");
    showNumbers(arr, size);
    radixSort(arr,size);
    printf("\n\nContents of Array After Sorting : \n");
    showNumbers(arr,size);
    exit(0);
}
