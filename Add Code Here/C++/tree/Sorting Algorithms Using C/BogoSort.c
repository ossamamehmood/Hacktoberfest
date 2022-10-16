#include "stdio.h"
#include "stdlib.h"

// Bogo Sort by Suman Roy
// HacktoberFest 2021

// Display numbers from array
void showNumbers(int* numbers, int size){
    int i=0;
    while(i<size){
        printf("[%d] ",numbers[i]);
        i++;
    }
    printf("\n");
}
// Check if the array is sorted correctly     
int is_sorted(int *array, int size)    
{        
    while ( --size >= 1 ) {        
        if ( array[size] < array[size-1] ) 
            return (0);    
    } 
    return (1);    
}
// Shuffle if not sorted correctly
void shuffleElements(int *array, int size)    
{        
    int i, t, temp;        
    for (i = 0;i < size;i++) {            
        t = array[i];
        temp = rand() % size;             
        array[i] = array[temp];            
        array[temp] = t;        
    }    
}
// Start Sorting
void BogoSort(int *array, int size)    
{        
    while (!is_sorted(array, size))             
    shuffleElements(array, size);    
}
// Driver Code
void main(){
    int array[]={22,3,57984,23,2511,324,526,3,4,5};
    int size=sizeof(array)/sizeof(array[0]);
    printf("\nArray Length = %d\nArray Before Sorting : \n\n",size);
    showNumbers(array, size);
    BogoSort(array, size);
    printf("\nArray After Sorting : \n\n");
    showNumbers(array, size);
    exit(0);
}