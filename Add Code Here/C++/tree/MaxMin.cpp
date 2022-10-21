#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    cout << "\n<<<========MaxMin array========>>>\n";

    int arr[5] = {10, 43, 12, 5, 300}, max, min;
    cout << "\nThe given array is : \n";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    min = arr[0];
    max = arr[0];
    for (int i = 0; i < 4; i++)
    {
        if (arr[i + 1] < min)
        {
            // max = min;
            min = arr[i + 1];
        }
        if (arr[i + 1] > max)
        {
            // min = max;
            max = arr[i + 1];
        }
    }
    cout << "\nMaximum element is : " << max << "\nMinimum element is : " << min;
}