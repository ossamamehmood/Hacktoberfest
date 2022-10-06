import java.util.Arrays;

public class knapSack_01 {
    public static int findMaxProfit(int totalWeight,int profit[], int weight[],int dp[][])
    {
        for(int i=1;i<=profit.length;i++)
        {
            for(int j=1;j<=totalWeight;j++)
            {
                int excluding=dp[i-1][j];
                int including=0;
                int currentWeight=weight[i-1];
                if(j>=currentWeight)
                {
                    including+=dp[i-1][j-currentWeight]+profit[i-1];
                }
                dp[i][j]=Math.max(excluding,including);
            }
        }
        return dp[profit.length][totalWeight];
    }
    public static int Profit(int totalWeight,int profit[], int weight[],int length)
    {
        int dp[][]=new int[length+1][totalWeight+1];
        return findMaxProfit(totalWeight, profit, weight, dp);

    }
    public static void main(String[] args) {
        int profit[]={20,30,10,50};
        int weight[]={1,3,4,6};
        int length=4;
        int totalWeight=10;
        System.out.println(Profit(totalWeight, profit, weight,length));
    }
}
