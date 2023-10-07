#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            // shifting start
            arr[j + 1] = arr[j];
            // shifting done
            j--;
        }
        arr[j + 1] = temp;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int n;
    cout << "Enter the total value " << endl;
    cin >> n;

    int arr[10];
    cout << "Put the value in an array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);
    cout << "Sorted array is(insertion sort) " << endl;
    printArray(arr, n);
}