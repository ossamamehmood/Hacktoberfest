#include <bits/stdc++.h>

using namespace std;

// DNF SORT
// ------------------------------------------------------------------------

// Sorting in ascending order
void dnfsort(int a[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
}

// Driver function

int main()
{
    int a[] = {1, 0, 1, 2, 0, 1, 1};
    int n = sizeof(a) / sizeof(int);

    dnfsort(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}