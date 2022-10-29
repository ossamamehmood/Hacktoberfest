// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int LCSub(vector<vector<int>> &dp, string &s, string &t, int n, int m)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {

            if (s[i - 1] == t[j - 1])
            {
                // lelo
                dp[i][j] = 1 + dp[i - 1][j - 1];
                // store the max
                ans = max(ans, dp[i][j]);
            }

            else
            {
                // since this is substring we don;t take after we get diff number/char
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int main()
{
    // Main function goes here
    return 0;
}