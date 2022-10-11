class Solution {
  public:
    int change(int amount, vector < int > & coins) {
      int dp[amount + 1][coins.size()];
      for (int j = 0; j < coins.size(); j++) dp[0][j] = 1;
      for (int i = 1; i < amount + 1; i++) {
        for (int j = 0; j < coins.size(); j++) {
          if (j == 0) {
            if (i % coins[j] == 0) dp[i][j] = 1;
            else dp[i][j] = 0;
          } else if (i - coins[j] >= 0) dp[i][j] = dp[i][j - 1] + dp[i - coins[j]][j];
          else
            dp[i][j] = dp[i][j - 1];
        }
      }
      return dp[amount][coins.size() - 1];
    }
};