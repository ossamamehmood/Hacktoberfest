class Solution {
public:
  int minDistance(string word1, string word2) {

    int length1 = word1.length();
    int length2 = word2.length();

    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1));

    for (int i = 1; i <= length1; ++i)
      dp[i][0] = i;

    for (int j = 1; j <= length2; ++j)
      dp[0][j] = j;

    for (int i = 1; i <= length1; ++i)
      for (int j = 1; j <= length2; ++j)
        if (word1[i - 1] == word2[j - 1])
          dp[i][j] = dp[i - 1][j - 1];
        else
          dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    return dp[length1][length2];
  }
};