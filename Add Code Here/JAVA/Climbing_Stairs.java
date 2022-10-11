import java.util.Arrays;

/**
 * Climbing_Stairs
 */
public class Climbing_Stairs {
    public static int climb(int n,int dp[])
    {
        if(n==0)
        return 1;
        if(n<0)
        return 0;
        if(dp[n]!=-1)
        return dp[n];

        int s1=climb(n-1,dp);
        int s2=climb(n-2,dp);

        return dp[n]=s1+s2;
    }
    public static void main(String[] args) {
        int n=4;
        int dp[]=new int[n+1];
        Arrays.fill(dp, -1);
        System.out.println(climb(n,dp));
    }
}