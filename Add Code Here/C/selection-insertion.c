// The following program does a comparison between Selection and Insertion sort in terms of time complexity.
// It generates 5 files with 100,000 random numbers in them and then sorts these number according to the sorting algorithm used.

#include <stdio.h> 
#include <sys/time.h>
#include <stdlib.h>
#define LIMIT 100000

//creating files
char filename[5][15]={"numbers_1.dat","numbers_2.dat","numbers_3.dat","numbers_4.dat","numbers_5.dat"};

void selection_sort(int a[],int n)
{
    int i, j, min, temp;
    //one by one traversing each number in array
    for (i = 0; i < n-1; i++)
    {
        // Finding minimum number
        min = i;
        for (j = i+1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        //swap if minimum number is found
        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }
}

void insertion_sort(int arr[], int n)
{
    int i, key, j;
    //to go through each element from arr[1] to arr[n]
    for (i = 1; i < n; i++)
    {
        key = arr[i]; //storing the element as temp 
        j = i - 1;

        while (j >= 0 && arr[j] > key)//to compare till arr[0] and value is greater than temp
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    struct timeval stop, start;
    int i,temp,a;
    int random_number;
    int arr[LIMIT];
    FILE *file; 
    float diff_sel[5];
    float diff_ins[5];

    //for loop for generating numbers, selection sort and insertion sort for 5 files
    for (a=0;a<5;a++)
    {   
        //to generate random numbers- file is opened, srand is used as seed with reference to time(0)
        //random numbers are generated using rand function
        file=fopen(filename[a],"w");
        srand((unsigned)time(0));
        i=0;
        do
        {
            random_number = (int) (rand()%1000) ;
            fprintf(file, "%d\n", random_number);
            i++;
        }while (i<LIMIT);
        fclose(file);

        file=fopen(filename[a],"r");
        i=0;
        do
        {
            fscanf(file, "%d", &arr[i]);
            i++;
        }while (i<LIMIT);
        fclose(file);
        gettimeofday(&start, NULL);
        insertion_sort(arr,i);
        gettimeofday(&stop, NULL);

        //to calculate the time taken in sorting
        diff_ins[a]=stop.tv_sec-start.tv_sec;
    
        //printing the result of insertion sort
        printf("\n\nDATASET        |   INSERTION SORT   |    SELECTION SORT    \n");
        printf("                         seconds               seconds         \n");
        printf("-----------------------------------------------------------\n");
        printf("%s\t\t%0.2f\t\t ",filename[a],diff_ins[a]);
    
        file=fopen(filename[a],"r");
        i=0;
        do
        {
            fscanf(file, "%d", &arr[i]);
            i++;
        }while (i<LIMIT);
        fclose(file);
        gettimeofday(&start, NULL);
        selection_sort(arr,i);
        gettimeofday(&stop, NULL);

        //to calculate the time taken in sorting
        diff_sel[a]=stop.tv_sec-start.tv_sec;

        //printing the result of selection sort
        printf("%0.2f\n",diff_sel[a]);
        printf("-----------------------------------------------------------\n");
    }  
    return 0;
}
