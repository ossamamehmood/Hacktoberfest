// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// MEMOIZED VERSION - 0/1 knapsack type
class Solution
{
public:
    int dp[601][101][101]; // since three variables are changing
    int helper(vector<string> &s, int m, int n, int start)
    {
        // base case
        if (m == 0 && n == 0)
        {
            return 0;
        }
        if (start >= s.size() || m < 0 || n < 0)
        {
            return 0;
        }

        if (dp[start][m][n] != -1)
        {
            return dp[start][m][n];
        }

        int count0 = count(s[start].begin(), s[start].end(), '0');
        int count1 = s[start].size() - count0;

        // recursive logic

        // lena h with maximization
        if (m - count0 >= 0 && n - count1 >= 0)
        {
            return dp[start][m][n] = max(1 + helper(s, m - count0, n - count1, start + 1), helper(s, m, n, start + 1));
        }
        // nehi lena h
        else
        {
            return dp[start][m][n] = helper(s, m, n, start + 1);
        }
    }

    int findMaxForm(vector<string> &s, int m, int n)
    {
        memset(dp, -1, sizeof(dp));
        int ans = helper(s, m, n, 0);
        return ans;
    }
};

// tabulation - FAST

class Solution
{
public:
    int findMaxForm(vector<string> &s, int m, int n)
    {
        int dp[101][101]{0};

        for (auto str : s)
        {
            int count0 = count(str.begin(), str.end(), '0');
            int count1 = str.size() - count0;

            for (int i = m; i >= 0; i--)
            {
                for (int j = n; j >= 0; j--)
                {
                    if (i >= count0 && j >= count1)
                    {
                        dp[i][j] = max(1 + dp[i - count0][j - count1], dp[i][j]);
                    }
                }
            }
        }

        return dp[m][n];
    }
};

int main()
{
    // Main function goes here
    return 0;
}