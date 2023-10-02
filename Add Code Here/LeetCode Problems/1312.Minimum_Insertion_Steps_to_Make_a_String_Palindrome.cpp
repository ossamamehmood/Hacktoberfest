class Solution {
public:
    int minInsertions(string s) {
        int n= s.length();
        vector<vector<int>>dp(n+1, vector<int>(n+1));

        //this is a basic variation of LCS, should be easy to understand
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(s[i]==s[n-1-j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }
                else{
                    dp[i+1][j+1]= max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        return n-dp[n][n];
    }
};
