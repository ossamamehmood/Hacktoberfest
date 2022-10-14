// Function for coin change problem using dynamic programming
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(amount + 1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0)
                dp[i][j] = INT_MAX - 1;
            if (j == 0)
                dp[i][j] = 0;
        }
    }
    for (int j = 1; j <= amount; j++)
    {
        if (j % coins[0] == 0)
        {
            dp[1][j] = j / coins[0];
        }
        else
        {
            dp[1][j] = INT_MAX - 1;
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[n][amount] == INT_MAX - 1)
        return -1;
    return dp[n][amount];
}