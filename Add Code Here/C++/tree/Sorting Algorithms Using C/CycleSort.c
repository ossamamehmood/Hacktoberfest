#include "stdio.h"
#include "stdlib.h"


// Heap Sort Algorithm by Suman Roy
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
// Swap function without temporary variable
void swap(int *a, int *b)
{
    *a=*a+*b;
    *b = *a-*b;
    *a = *a-*b;
}
 
void cycleSort(int arr[], int n)
{
    int cycle_start;
    for (cycle_start = 0; cycle_start <= n - 2; ++cycle_start) {
        int item = arr[cycle_start]; 
        int pos = cycle_start;

        int i;
        for (i = cycle_start + 1; i < n; ++i)
            if (arr[i] < item)
                ++pos;

        if (pos == cycle_start)
            continue;
 
        while (item == arr[pos])
            ++pos;
 
        if (pos != cycle_start)
            swap(&item, &arr[pos]);
 
        while (pos != cycle_start) {
            pos = cycle_start;
 
            for (i = cycle_start + 1; i < n; i++)
                if (arr[i] < item)
                    ++pos;
 
            while (item == arr[pos])
                ++pos;
 
            if (item != arr[pos])
                swap(&item, &arr[pos]);
        }
    }
}



// Main
void main(){
    printf("\nCycle Sort Algorithm");
    int arr[] = {275,128,28,249,433,91,288,12,29,179,248,479,487,42,153,191,132,323,205,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("\nSize of Array = %d\n",size);
    printf("\n\nContents of Array Before Sorting : \n");
    showNumbers(arr, size);
    cycleSort(arr,size);
    printf("\n\nContents of Array After Sorting : \n");
    showNumbers(arr,size);
    exit(0);
}