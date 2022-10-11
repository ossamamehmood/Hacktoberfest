import java.util.Arrays;

/**
 * House_Robbers
 */
public class House_Robbers {
    public static int robForm(int wealth[],int currIndex,int dp[])
    {
        if(currIndex>=wealth.length)
        return 0;
        if(dp[currIndex]!=-1)
        return dp[currIndex];

        int stealCurrent=wealth[currIndex]+robForm(wealth, currIndex+2,dp);
        int skipCurrent=robForm(wealth, currIndex+1,dp);

        return dp[currIndex]=Math.max(stealCurrent, skipCurrent);

    }
    public static void main(String[] args) {
        int nums[]={114,117,207,117,235,82,90,67,143,146,53,108,200,91,80,223,58,170,110,236,81,90,222,160,165,195,187,199,114,235,197,187,69,129,64,214,228,78,188,67,205,94,205,169,241,202,144,240};
        int dp[]=new int[nums.length];
        Arrays.fill(dp, -1);
        System.out.println(robForm(nums,0,dp));
    }
}