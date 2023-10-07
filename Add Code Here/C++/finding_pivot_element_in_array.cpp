#include <bits/stdc++.h>
using namespace std;
int minn(int a[], int h)
{
    int l = 0;

    int m = l + (h - l) / 2;

    while (l < h)
    {

        if (a[m] >= a[0])
        {

            l = m + 1;
        }
        else
        {
            h = m;
        }
        m = l + (h - l) / 2;
    }
    return h;
}
int main()
{
    int a[] = {4, 5, 1, 2, 3};
    int n = sizeof(a) / sizeof(a[0]);

    cout << a[minn(a, n - 1)] << endl;
}