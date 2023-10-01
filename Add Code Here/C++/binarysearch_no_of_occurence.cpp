#include <bits/stdc++.h>
using namespace std;
int firstocc(int a[], int l, int h, int k)
{
    int m = l + (h - l) / 2;
    int ans;
    while (l <= h)
    {
        if (a[m] == k)
        {
            ans = m;
            h = m - 1;
        }
        else if (a[m] < k)
        {

            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
        m = l + (h - l) / 2;
    }
    return ans;
}
int lastocc(int a[], int l, int h, int k)
{
    int m = l + (h - l) / 2;
    int ans;
    while (l <= h)
    {
        if (a[m] == k)
        {
            ans = m;
            l = m + 1;
        }
        else if (a[m] < k)
        {

            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
        m = l + (h - l) / 2;
    }
    return ans;
}
int main()
{
    int a[] = {1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    cout << lastocc(a, 0, n - 1, k) - firstocc(a, 0, n - 1, k) + 1 << endl;
}