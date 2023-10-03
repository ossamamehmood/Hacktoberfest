#include <bits/stdc++.h>
using namespace std;
int minn(int a[], int h)
{
    int l = 0;

    int m = l + (h - l) / 2;

    while (l < h)
    {

        if (a[m] > a[m + 1])
        {

            l = m + 1;
        }
        else
        {
            h = m;
        }
        m = l + (h - l) / 2;
    }
    return l;
}
int main()
{
    int a[] = {9, 8, 7, 6, 5, 4, 3, 0, 2, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);

    cout << a[minn(a, n - 1)] << endl;
}