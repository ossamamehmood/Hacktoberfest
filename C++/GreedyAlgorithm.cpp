#include <iostream>
using namespace std;

// Finding the minimum sum of product of two arrays

int minpro(int a[], int b[], int n, int k)
{
    int dif = 0, r = 0;
    int temp;
    for (int i = 0; i < n; i++)
    {
        int p = a[i] * b[i];
        r = r + p;
        if (p < 0 && b[i] < 0)
            temp = (a[i] + 2 * k) * b[i];
        else if (p < 0 && a[i] < 0)
            temp = (a[i] + 2 * k) * b[i];
        else if (p > 0 && a[i] < 0)
            temp = (a[i] + 2 * k) * b[i];
        else if (p > 0 && a[i] > 0)
            temp = (a[i] - 2 * k) * b[i];
        int d = abs(p - temp);
        if (d > dif)
            dif = d;
    }
    return r - dif;
}

int main()
{
    int a[] = {12, 45, 2, 7, 2};
    int b[] = {7, 8, 6, 7, 6};
    int n = 5, k = 3;
    cout << minpro(a, b, n, k) << endl;
    return 0;
}