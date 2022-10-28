// Meta Hacker Cup 2022
// Link: https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/B1
// Problem B1: Watering Well - Chapter 1
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define pb push_back
#define endl '\n'
#define sa(x) sort((x).begin(), (x).end());
#define int long long

template <typename T>
static inline void sd(vector<T> &x)
{
    sort((x).begin(), (x).end(), greater<T>());
}
#define mod (int)(1e9 + 7)

void solve()
{
    int n;
    cin >> n;
    vector<int> x, y;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    int q;
    cin >> q;
    vector<int> xx, yy;
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        xx.push_back(a);
        yy.push_back(b);
    }
    // sort(xx.begin(),xx.end());
    // sort(yy.begin(),yy.end());

    int ans = 0;
    int sumx = 0, sumy, sumxx = 0, sumyy = 0;
    for (int i = 0; i < n; i++)
    {
        sumx += (x[i]);
        sumx %= mod;
        sumy += (y[i]);
        sumy %= mod;
    }
    for (int i = 0; i < q; i++)
    {
        sumxx += (xx[i]);
        sumxx %= mod;
        sumyy += (yy[i]);
        sumyy %= mod;
    }

    for (int i = 0; i < n; i++)
    {
        int val = x[i] * x[i];
        val %= mod;
        val *= q;
        val %= mod;
        ans += val;
        ans %= mod;

        val = y[i] * y[i];
        val %= mod;
        val *= q;
        val %= mod;
        ans += val;
        ans %= mod;

        ans = (ans - (2 * x[i] * sumxx) % mod + mod) % mod;
        ans = (ans - (2 * y[i] * sumyy) % mod + mod) % mod;
    }
    for (int i = 0; i < q; i++)
    {
        int val = xx[i] * xx[i];
        val %= mod;
        val *= n;
        val %= mod;
        ans += val;
        ans %= mod;
        val = yy[i] * yy[i];
        val %= mod;
        val *= n;
        val %= mod;
        ans += val;
        ans %= mod;
    }

    cout << ans << endl;
}

signed main()
{
    freopen("input.txt", "r", stdin);
    // Printing the Output to output.txt file
    freopen("output.txt", "w", stdout);
    int testcases = 1;
    cin >> testcases;
    int case_num = 1;
    while (testcases--)
    {
        cout << "Case #" << case_num << ":"
             << " ";
        solve();
        case_num++;
    }
    return 0;
}