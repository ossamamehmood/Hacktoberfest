// Reverse Integer

#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
    long long f = 1;
    if (x < 0)
        f = -1;
    x *= f;
    long long ans = 0;
    while (x)
    {
        int tem = x % 10;
        ans = ans * 10 + tem;
        x /= 10;
    }
    ans *= f;
    if (ans > INT_MAX || ans < INT_MIN)
        return 0;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int reversed = reverse(n);
    cout << reversed << endl;
    return 0;
}