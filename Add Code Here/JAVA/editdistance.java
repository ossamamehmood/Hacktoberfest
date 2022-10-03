
class Solution {
    public int editDistance(String s, String t) {
        // Code here
        int m = s.length();
        int n = t.length();
        int[][] dp = new int[m+1][n+1];
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0)
                dp[i][j] = j;
                else if(j==0)
                dp[i][j] = i;
                else if(s.charAt(i-1)==t.charAt(j-1))
                dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + Math.min(dp[i-1][j],Math.min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }
}
