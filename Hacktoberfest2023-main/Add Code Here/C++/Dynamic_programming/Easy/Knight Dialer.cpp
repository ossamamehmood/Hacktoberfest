//Link: https://leetcode.com/problems/knight-dialer/description/

class Solution {
public:
    int knightDialer(int n)
{
    vector<vector<int>> a = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
    int mod = 1e9 + 7;
    long long int ans = 0;
    vector<vector<long long int>> dp(n + 1, vector<long long int>(10, 0));
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    for (int i = 2; i < n + 1; i++)
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < a[j].size(); k++)
                dp[i][j] += dp[i - 1][a[j][k]];
            dp[i][j] %= mod;
        }

    for (auto x : dp[n])
        ans += x;

    return ans % mod;
}
};
