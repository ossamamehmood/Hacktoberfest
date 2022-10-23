#include<bits/stdc++.h>
using namespace std;
const int RUN = 32;
 

void insertionSort(int arr[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}
 

void merge(int arr[], int l, int m, int r)
{
     
   
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
 
    int i = 0;
    int j = 0;
    int k = l;
 
    
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
 
    // Copy remaining elements of left, if any
    while (i < len1)
    {
        arr[k] = left[i];
        k++;
        i++;
    }
 
   
    while (j < len2)
    {
        arr[k] = right[j];
        k++;
        j++;
    }
}
 

void timSort(int arr[], int n)
{
     
    
    for (int i = 0; i < n; i+=RUN)
        insertionSort(arr, i, min((i+RUN-1),
                                    (n-1)));
 
    
    for (int size = RUN; size < n;
                             size = 2*size)
    {
         
        
        for (int left = 0; left < n;
                             left += 2*size)
        {
             
            y
            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                                            (n-1));
 
              if(mid < right)
                merge(arr, left, mid, right);
        }
    }
}
 

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n");
}
 

int main()
{
    int arr[] = {-2, 7, 15, -14, 0, 15, 0, 7, -7,
                       -4, -13, 5, 8, -14, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Given Array is\n");
    printArray(arr, n);
 
    // Function Call
    timSort(arr, n);
 
    printf("After Sorting Array is\n");
    printArray(arr, n);
    return 0;
}
