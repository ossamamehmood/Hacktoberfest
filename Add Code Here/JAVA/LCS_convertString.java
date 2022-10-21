public class LCS_convertString {
    public static int findLCS(String s1,String s2)
    {
        int m=s1.length();
        int n=s2.length();
        int dp[][]=new int[m+1][n+1];
        for(int i=0;i<=m;i++)
        dp[i][0]=i;
        for(int j=0;j<=n;j++)
        dp[0][j]=j;

        return LCS(m, n, s1, s2, dp);

    }
    public static int LCS(int m,int n,String s1,String s2,int dp[][])
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1.charAt(i-1)==s2.charAt(j-1))
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j]=Math.min(dp[i-1][j-1], Math.min(dp[i-1][j], dp[i][j-1]))+1;
            }
        }
        return dp[m][n];
    }
    public static void main(String[] args) {
        // String s1="ABCAB";
        // String s2="EACB";
        String s1="DOG";
        String s2="DIG";
        System.out.println(findLCS(s1, s2));
    }
}
