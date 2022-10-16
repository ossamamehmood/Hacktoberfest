#include <stdio.h>
#include <iostream>
#include <limits.h> //for using INT_MAX and INT_MIN.
using namespace std;

int minimizeHeight(int arr1[], int k, int n1)
{
    int max = INT_MIN;
    int min = INT_MAX;
    for (int i = 0; i < n1; i++)
    {
        if ((arr1[i] - k) >= 0)
        {
            arr1[i] = arr1[i] + k;
        }
        if (max < arr1[i])
        {
            max = arr1[i];
        }
        if (min >= arr1[i])
        {
            min = arr1[i];
        }
    }
    cout << "\nModified array is : \n";
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\nMaximum element is : " << max;
    cout << "\nMinimum element is : " << min;
    cout << "\nDifference between maximum and minimum element of the modified array is : " << (max - min) << "     ";
    return 0;
}

int main()
{
    int n1, k;
    cout << "Enter the size of the array : ";
    cin >> n1;
    int arr1[1000];
    cout << "\nEnter " << n1 << " elements for array : ";
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    cout << "\nEntered elements in array : ";
    for (int i = 0; i < n1; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\nEnter the modifying parameter : ";
    cin >> k;
    cout << "\nWe need to modify by " << k << " to each array value.";
    minimizeHeight(arr1, k, n1);
    return 0;
}