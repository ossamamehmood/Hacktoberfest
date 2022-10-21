import java.util.*;
public class Solution
{
    public static int maxsteal(int index,int bagweight,int[] weight, int[] value,int[][]dp)
    {
        if(index==0)
        {
            if(weight[0]<=bagweight)
            {
                return value[0];
            }
            else
            {
                return 0;
            }
        }
        if(dp[index][bagweight]!=-1)
        {
            return dp[index][bagweight];
        }
        int take=Integer.MIN_VALUE;
        int nottake=0+maxsteal(index-1,bagweight,weight,value,dp);
        
        //Now check conditions for take
        if(weight[index]<=bagweight)
        {
            take=value[index]+maxsteal(index-1,bagweight-weight[index],weight,value,dp);
        }
        
        return dp[index][bagweight]=Math.max(take,nottake);
    }
    static int knapsack(int[] weight, int[] value, int n, int maxWeight) 
    {
        //Pick and Dont pick Concept
        //DP Approach
        //Since we have two parameters changing
        int[][]dp=new int[n][maxWeight+1];
        for (int i = 0; i < n; i++) 
        {
            Arrays.fill(dp[i], -1);
        }
        return maxsteal(n-1,maxWeight,weight,value,dp);

    }
}
