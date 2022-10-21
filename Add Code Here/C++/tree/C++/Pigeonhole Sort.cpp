#include <bits/stdc++.h>
using namespace std;

void PigSort(int arr[], int n)
{
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
    int range = max - min + 1;
    vector<int> holes[range];
    for (int i = 0; i < n; i++)
        holes[arr[i] - min].push_back(arr[i]);
    int index = 0;
    for (int i = 0; i < range; i++)
    {
        vector<int>::iterator it;
        for (it = holes[i].begin(); it != holes[i].end(); ++it)
            arr[index++] = *it;
    }
}

int main()
{
    int n;
    cout << "Enter the size of Array: ";
    cin >> n;
    cout << "Enter the Array: ";
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    PigSort(arr, n);
    cout << "\nThe Sorted order is :";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}