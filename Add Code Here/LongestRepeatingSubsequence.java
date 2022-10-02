import java.util.*;
public class Solution
{
    public static int lrs(int index1,int index2,String a,int[][]dp)
    {
        //Base Case
        if(index1<0 || index2<0)
        {
            return 0;
        }
        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }
        //Match case
        if((a.charAt(index1)==a.charAt(index2)) && index1!=index2)
        {
            return dp[index1][index2]=1+lrs(index1-1,index2-1,a,dp);
        }
        
        //Not Match
        return dp[index1][index2]=0+Math.max(lrs(index1-1,index2,a,dp),lrs(index1,index2-1,a,dp));
    }
    public static int longestRepeatingSubsequence(String st, int n)
    {
        // Write your coder here.
        //Similar to LCS 
        //the only change is that we need to make sure index1!=index2
        int[][]dp=new int[n][n];
        for (int i = 0; i < n; i++) 
        {
            Arrays.fill(dp[i], -1);
        }

        return lrs(n-1,n-1,st,dp);
    }
}
