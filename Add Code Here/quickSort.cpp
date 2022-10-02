#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int temp;
    int pivot = low, left = (low + 1), right = high;

    while (right >= left)
    {
        if (arr[left] < arr[pivot])
        {
            left++;
        }
        else
        {
            if (arr[right] > arr[pivot])
            {
                right--;
            }
            else
            {
                temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
            }
        }
    }
    if (right < left)
    {
        temp = arr[pivot];
        arr[pivot] = arr[right];
        arr[right] = temp;
        return right;
    }
    return 0;
}

void quickSort(int arr[], int low, int high)
{
    int pivot;
    if (high > low)
    {
        pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr1[8] = {20, 5, 15, 30, 80, 25, 3, 1};
    cout<<"The Initial array : \n";
    printArr(arr1, 8);
    quickSort(arr1, 0, 7);
    cout<<"\nThe Sorted array : \n";
    printArr(arr1, 8);
    return 0;
}