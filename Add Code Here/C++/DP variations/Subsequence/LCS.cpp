// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        if (LCS(dp, s, t, n, m) == n)
            return true;
        return false;
    }

    int LCS(vector<vector<int>> dp, string s, string t, int n, int m)
    {

        // Already they are 0

        // for (int i = 0; i < n; i++)
        //     dp[i][0] = 0;
        // for (int j = 0; j < m; j++)
        //     dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                if (s[i - 1] == t[j - 1])
                {
                    // remove 1 from both i.e take both
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // take wo wala jisko leke max val ayega
                    // take max of both since it is subsequence . if it was substr we should have taken 0
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[n][m];
    }
};


int main()
{
    // Main function goes here
    return 0;
}



// comment added