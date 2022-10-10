#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int reverseNo = 0;
int ReverseNo(int n)
{

    if (n < 10)
    {
        return n;
    }

    else
    {
        cout << n % 10;
        ReverseNo(n / 10);
    }
}

int main()
{
    cout << "pls enter the number" << endl;
    int n;
    cin >> n;

    int z = ReverseNo(n);
    cout << z;

    return 0;
}
