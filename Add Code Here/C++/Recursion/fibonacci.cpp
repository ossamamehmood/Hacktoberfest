#include <iostream>
using namespace std;
int fibo(int n)
{
    int arr[50];
    for (int i = 0; i < n; i++)
    {
        arr[i] = -1;
    }
    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        if (arr[n-2] == -1)
        {
            arr[n - 2] = fibo(n - 2);
        }
        if (arr[n-1] == -1)
        {
            arr[n - 1] = fibo(n - 1);
        }
        return arr[n - 2] + arr[n - 1];
    }
}
int fibofor(int n)
{
    int s, t0 = 0, t1 = 1;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}
int main()
{
    int a = 4;
    cout << fibo(45);
    return 0;
}