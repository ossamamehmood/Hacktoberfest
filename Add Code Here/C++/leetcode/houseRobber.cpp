int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
	    //return solve(nums,0,dp);
        int n=nums.size();
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int op1=dp[i-1];
            int op2=(i-2>=0)?dp[i-2]+nums[i]:nums[i];
            dp[i]=max(op1,op2);
        }

        return dp[n-1];
        }