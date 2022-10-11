public class Coin_Change_BottomUp_Approach {
    public static int coinChange(int coin[],int amt,int dp[][])
    {
        for(int i=1;i<=coin.length;i++)
        {
            for (int j = 1; j <=amt; j++) {
                if(coin[i-1]>j)
                dp[i][j]=dp[i-1][j];
                else
                dp[i][j]=Math.min(dp[i-1][j],1+dp[i][j-coin[i-1]]);
            }
        }
        return dp[amt][coin.length];
    }
    public static void main(String[] args) {
        int coin[]={1,5,6,9};
        int amt=10;
        int dp[][]=new int [amt+1][coin.length+1];
        for(int i=0;i<=amt;i++) dp[i][0]=i;
        for(int j=0;j<=coin.length;j++) dp[0][j]=j;

        System.out.println(coinChange(coin,amt,dp));
    }   
}
