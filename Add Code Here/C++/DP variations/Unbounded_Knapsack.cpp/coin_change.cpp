// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Template

// int minFallingPathSum(vector<vector<int>> &matrix)
// {
//     int n = matrix.size();
//     vector<vector<int>> dp(n, vector<int>(n, -1));

//     for (int i = 1; i <= n; i++)
//    {
//           for (int j = 1; j <= t; j++)
//           {
//             if (coins[i] <= j)
//             {
//                 dp[j] = min(dp[j], dp[j - coins[i]] + 1);
//             }
//          ]
//     }
// }

// solution

class Solution
{
public:
    // Unbounded knapsack variation

    // Time Complexity :::  O(mn)
    // Space Complexity ::: O(mn)

    int coinChange(vector<int> &coins, int t)
    {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(t + 1, INT_MAX - 5));

        // with 0 coins are there we can't form any amount or we need inf coins
        for (int i = 0; i <= t; i++)
        {
            dp[0][i] = INT_MAX - 5;
        }

        // amount 0 can can be achieved by all coins taking 0 no of coins
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }

        // Real dp starts from here
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= t; j++)
            {

                // coin itself is geater than target don't take that ith coin
                if (coins[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                } // else take min ( nehi lena hein    ||    lena h ) ->if le rhe ho then +1 becoz we are taking one coin and decrement the target val j by that coin i.e coins[i-1]
                else
                {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - (coins[i - 1])] + 1);
                }
            }
        }

        return dp[n][t] != INT_MAX - 5 ? dp[n][t] : -1;
    }
};

int main()
{
    // Main function goes here
    return 0;
}