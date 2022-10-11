import java.util.Arrays;

public class CoinChange
{
    public static void main(String[] args) {
        int n=18;
        int a[]={8,5,1};
        int dp[]=new int[n+1];
        Arrays.fill(dp, -1);

        dp[0]=0;
        System.out.println(minCoins(n, a,dp));
        for (int i = 0; i < dp.length; i++) {
            System.out.print(i+" ");
        }
        System.out.println();
        for (int i = 0; i < dp.length; i++) {
                System.out.print(dp[i]+" ");
            
        }
    }
    static int minCoins(int n,int a[],int dp[])
    {
        if(n==0)
        return 0;

        int ans=Integer.MAX_VALUE;
        for (int i = 0; i < a.length; i++) {
            if(n-a[i]>=0)
            {
                int subans=0;
                if(dp[n-a[i]]!=-1)
                {
                    subans=dp[n-a[i]];
                }
                else{
                subans=minCoins(n-a[i], a,dp);
                }
                if(subans+1<ans &&subans!=Integer.MAX_VALUE)
                {
                    ans=subans+1;
                }
            }   
        }
        dp[n]=ans;
        return ans;
    }
}