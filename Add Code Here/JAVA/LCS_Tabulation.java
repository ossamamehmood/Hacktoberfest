public class LCS_Tabulation {
    static int lcs(int m, int n, String a, String b)
    {
        int dp[][]=new int[m+1][n+1];
        return lcsUtil(m, n, a, b,dp);
    }
    static int lcsUtil(int m,int n,String a, String b,int dp[][])
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a.charAt(i-1)==b.charAt(j-1))
                dp[i][j]=dp[i-1][j-1]+1;
                else
                dp[i][j]=Math.max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
    public static void main(String[] args) {
        System.out.println(lcs(4, 5, "abcd", "bcedf"));
    }
}
