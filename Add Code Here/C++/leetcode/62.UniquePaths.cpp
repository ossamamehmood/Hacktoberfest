class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i>0 && j>0){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
                else if(i>0){
                    dp[i][j]=dp[i-1][j];
                }
                else if(j>0){
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};