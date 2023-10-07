#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'

const ll mod = 1e9 + 7;

ll binaryExponentiation(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll number = 5;
    ll power = 2;
    cout << binaryExponentiation(5, 2) << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
