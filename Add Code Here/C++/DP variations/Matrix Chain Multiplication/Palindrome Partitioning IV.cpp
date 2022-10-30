// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// BRUTE FORCE with dp in palindrome checking

class Solution
{
public:
    vector<vector<int>> dp;

    int checkPartitioning(string &s)
    {
        int n = s.size();
        dp.resize(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                if (palindrome(s, 0, i) && palindrome(s, i + 1, j) && palindrome(s, j + 1, n - 1))
                {
                    return true;
                }
            }
        }

        return false;
    }

    // use dp to store this
    bool palindrome(string &s, int i, int j)
    {
        if (i >= j)
            return true;

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        // Recursion
        if (s[i] == s[j])
        {
            return dp[i][j] = palindrome(s, i + 1, j - 1);
        }
        else
        {
            return dp[i][j] = false;
        }

        return true;
    }
};

int main()
{
    // Main function goes here
    return 0;
}