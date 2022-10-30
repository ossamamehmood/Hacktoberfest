// Shibam Debnath
// July ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        int dp[m + 1][n + 1];

        for (int i = 0; i < n; i++)
        {
            dp[m - 1][i] = 1;
        }

        for (int i = m - 2; i >= 0; i--)
        {
            dp[i][n - 1] = 1; // initializing last column as 1
            for (int j = n - 2; j >= 0; j--)
            {
                dp[i][j] = dp[i][j + 1] + dp[i + 1][j];
            }
        }

        return dp[0][0];
    }
};

int main()
{
    // Main function goes here
    return 0;
}