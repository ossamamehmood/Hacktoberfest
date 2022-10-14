/*
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
    int n=nums.size();
 
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum+target)%2!=0) return 0;
        int m=(sum+target)/2;
        if(m<0) return 0;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++){
            if(nums[i-1]==0) dp[i][0]=2*dp[i-1][0];
            else dp[i][0]=dp[i-1][0];
            // cout<<dp[i][0]<<endl;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(nums[i-1]>j)
                    dp[i][j]=dp[i-1][j];
                else 
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
        }
        
       return dp[n][m]; 
        
        
    }
};
