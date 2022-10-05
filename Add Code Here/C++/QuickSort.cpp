#include <iostream>
using namespace std;

int partition(int arr[], int s, int e){
     
    int pivot = arr[s];

    int cnt = 0;
    for (int i = s+1; i <= e; i++)
    {
        if(arr[i] <= pivot){
            cnt++;
        }
    }

    //place pivot in right place
    int pivotIndex = s+cnt;
    swap(arr[s] , arr[pivotIndex]);

    //now arrange left and right part properly
    int i = s;
    int j = e;

    while ( i < pivotIndex && j > pivotIndex)
    {
       while (arr[i] <= pivot)
       {
          i++;
       }

       while (arr[j] > pivot)
       {
          j--;
       }

       if(i < pivotIndex && j > pivotIndex){
           swap(arr[i++], arr[j--]);
       }
       
    }

    return pivotIndex;

    
}

void quickSort(int arr[], int s, int e){

    //base case
    if(s>=e){
        return;
    }

    int p = partition(arr, s, e);

    quickSort(arr, s, p-1);

    quickSort(arr, p+1, e);
}

int main(){
    int arr[10] = {2, 4, 3, 1, 3, 6, 7, 8, 4, 0};
    int n = 10;

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
       cout << arr[i]<<" ";
    }
    
}