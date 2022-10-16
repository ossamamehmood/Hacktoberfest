#include "stdio.h"
#include "stdlib.h"

// Shell Sorting by Suman Roy
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

// Start Sorting    
int* shellSort(int* array, int size){
        int i, j, k, tmp;
        // divide the length into 2 sub arrays
            for (i = size / 2; i > 0; i = i / 2)    
                {
                // iterate through the elements
                for (j = i; j < size; j++)    
                    {    
                    for(k = j - i; k >= 0; k = k - i)    
                        {    
                        if (array[k+i] >= array[k])    
                            break;    
                        else    
                        {
                        // Swap values
                        tmp = array[k];
                        array[k] = array[k+i];    
                        array[k+i] = tmp;
                        }
                    }
                }
            }
        }

void main(){
    int array[]={22,3,57984,23,2511,324,526,3,4,5};
    int size=sizeof(array)/sizeof(array[0]);
    printf("\nArray Length = %d\nArray Before Sorting : \n\n",size);
    showNumbers(array, size);
    shellSort(array, size);
    printf("\nArray After Sorting : \n\n");
    showNumbers(array, size);
    exit(0);
}