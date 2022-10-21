/**
 * Longest_Common_Substring
 */
public class Longest_Common_Substring {
    public static int LCSmin(int m,int n,String s1, String s2)
    {
        int dp[][]=new int [m+1][n+1];
        return findLCS(m, n, s1, s2, dp);

    }
    public static int findLCS(int m,int n,String s1, String s2,int dp[][])
    {
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1.charAt(i-1)==s2.charAt(j-1))
                dp[i][j]=dp[i-1][j-1]+1;

                ans=Math.max(ans, dp[i][j]);
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        String s1="BABCDD";
        String s2="ABCDADE";

        System.out.println(LCSmin(s1.length(), s2.length(), s1, s2));

    }
}