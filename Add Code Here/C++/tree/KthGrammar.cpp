#include <iostream>
#include <math.h>
using namespace std;

int kgrammar(int n, int k)
{
    int i;
    if (k > pow(2, n - 1) || k<1)
        return -1;
    else
    {
        if (n == 1)
            return 1;

        int l = (k / 2) + (k % 2);
        i = kgrammar(n - 1, l);
        bool num;
        if (k % 2 == 0)
            num = 0;
        else
            num = 0;
        if (i == 0)
            return num;
        else
            return !num;
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout << kgrammar(n,k);
    return 0;
}