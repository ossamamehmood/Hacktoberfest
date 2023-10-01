//Link: https://leetcode.com/problems/minimum-cost-to-merge-stones/description/

    int mergeStones(vector<int>& stones, int K) 
    {
      int N = stones.size();
      if ((N-1)%(K-1) > 0) return -1; // validation to merge into a single pile
      
      // partial sum
      int sum[N+1] = {0};
      for (int i = 1; i <= N; i++)
        sum[i] = sum[i-1] + stones[i-1];
      
      // dp[i][j]: the minimum cost needed to merge stones[i] ~ stones[j] 
      // with the left most element stones[i] always involved in merge if possible
      vector<vector<int>> dp(N, vector<int>(N, 0));
      
      for (int L = K; L <= N; L++) // L: length of interval [i,j]
        for (int i = 0, j = i+L-1; j < N; i++, j++) { // each interval [i,j] of length L in [0,N]
          
          dp[i][j] = INT_MAX;          
          
          // when stones[i] is merged, it must be merged with multiple of (K-1) other stones
          for (int k = i; k < j; k += (K-1))
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
          
          // all stones in [i,j] can be merged into one pile
          if ((L-1)%(K-1) == 0)
            dp[i][j] += (sum[j+1] - sum[i]); // add sum in [i,j]
        }
      
      return dp[0][N-1];
    }
