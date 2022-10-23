#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

#define endl "\n"

#define tc_ll \
    lli t;    \
    cin >> t; \
    while (t--)

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int mod(int x)
{
    return x >= 0 ? x : -x;
}

// using tabulation --> super memory optimization --> reduced the table to only one row i.e a 1-D array
// T.C = O(n*sum)
// S.C = O(sum)
int main()
{
    fast

        tc_ll
    {
        int n, sum;
        cin >> n >> sum;
        int arr[n + 1];
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        bool dp[sum + 1];
        dp[0] = 1;

        for (int i = 1; i <= sum; i++)
        {
            dp[i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (j - arr[i] >= 0)
                {
                    dp[j] |= dp[j - arr[i]];
                }
            }
        }

        cout << dp[sum] << endl;
    }
    return 0;
}
