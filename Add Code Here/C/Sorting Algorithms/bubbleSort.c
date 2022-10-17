#include <stdio.h>

int main(){

    int arr[50], num, x, y, temp;    

    printf("Please Enter the Number of Elements you want in the array: ");

    scanf("%d", &num);    

    printf("Please Enter the Value of Elements: ");

    for(x = 0; x < num; x++)

        scanf("%d", &arr[x]);
    
    int i, j;
    
    bool swapped;

    for(x = 0; x < num - 1; x++){
        
        swapped = false;

        for(y = 0; y < num - x - 1; y++){          

            if(arr[y] > arr[y + 1]){               

                temp = arr[y];

                arr[y] = arr[y + 1];

                arr[y + 1] = temp;

            }

        }
        
         // IF no two elements were swapped by inner loop, then break
       if (swapped == false)
           
        break;

    }

    printf("Array after implementing bubble sort: ");

    for(x = 0; x < num; x++){

        printf("%d  ", arr[x]);

    }

    return 0;

}
