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
    int a[] = {1, 2, 3, 3, 3, 3, 5};
    int n = 7;
    int k = 3;
    cout << "first occurence--" << firstocc(a, 0, n - 1, k) << endl;
    cout << "last occurence--" << lastocc(a, 0, n - 1, k) << endl;
}