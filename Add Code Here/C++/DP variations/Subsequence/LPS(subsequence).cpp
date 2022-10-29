// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string t = s;
        reverse(t.begin(), s.begin());
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        return LIS(dp, s, t);
    }

    int LIS(vector<vector<int>> &dp, string &s, string &t)
    {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        return LIS(dp, t, s);
    }

    int LIS(vector<vector<int>> &dp, string &s, string &t)
    {

        int n = s.size();

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                if (s[i - 1] == t[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];

                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][n];
    }
};

// without extra string (optimized version)

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        if (s.empty())
            return 0;

        const int N = s.size();
        // dp(i, j): length of longest palindromic substring in s[i:j]
        vector<vector<int>> dp(N, vector<int>(N, 0));

        // all single chars are palindromic
        for (int i = 0; i < N; i++)
            dp[i][i] = 1;

        for (int l = 1; l < N; l++)
        {
            // starting index of window
            for (int i = 0; i < N - l; i++)
            {
                // ending index of window
                int j = i + l;

                // if there are only two chars
                if ((j - i + 1) == 2)
                {
                    // if the chars are same, then that contributes 2, otherwise since
                    // individually they are palindromic so max length 1
                    dp[i][j] = 1 + (s[i] == s[j]);
                }
                else
                {
                    // for s[i:j]:
                    // longest palindrome length in s[i+1 : j-1] and +1 if s[i] == s[j]
                    // if s[i] != s[j], longest length palindrome = Max of longest palin in s[i:j-1] and s[i+1:j]
                    if (s[i] == s[j])
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    else
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][N - 1];
    }
};

int main()
{
    // Main function goes here
    return 0;
}