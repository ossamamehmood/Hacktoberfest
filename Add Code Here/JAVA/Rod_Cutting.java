import java.util.Arrays;

public class Rod_Cutting {
    public static int findProfit(int length,int profit[],int dp[])
    {
        for(int i=1;i<=length;i++)
        {
           for(int j=0;j<i;j++)
           {
            dp[i]=Math.max(dp[i], profit[j]+dp[i-j-1]);
           }
        }
        return dp[length];
    }
    
    public static void main(String[] args) {
        int length=8;
        int profit[]={1,5,6,9,11,12,14,16};
        int dp[]=new int[length+1];
        System.out.println(findProfit(length, profit, dp));
    }
}
