import java.util.*;
public class Solution 
{
    public static long countways(int index,int target,int[]a,long[][]dp)
    {
        if(index==0)
        {
            if(target%a[index]==0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        
        long take=0;
        long nottake=countways(index-1,target,a,dp);
        
        if(a[index]<=target)
        {
            take=countways(index,target-a[index],a,dp);
        }
        
        return dp[index][target]=nottake+take;
    }
    public static long countWaysToMakeChange(int denominations[], int value)
    {
        int n=denominations.length;
        long[][]dp=new long[n][value+1];
        for (int i = 0; i < n; i++) 
        {
            Arrays.fill(dp[i], -1);
        }
        return countways(n-1,value,denominations,dp);
    }
    
}
