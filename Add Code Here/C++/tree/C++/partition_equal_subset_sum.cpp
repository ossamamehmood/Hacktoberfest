class Solution {
public:
    bool partition(vector<int>&nums,int sum,int n,vector<vector<int>>&dp){
        if(sum==0){
            return true;
        }
        if(n==0){
            return false;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];   
        }
        if(nums[n-1]<=sum){
            dp[n][sum]=partition(nums,sum-nums[n-1],n-1,dp)||partition(nums,sum,n-1,dp);
        }
        else{
            dp[n][sum]=partition(nums,sum,n-1,dp);
        }
        return dp[n][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0,i,j,n=nums.size();
        for(i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        sum/=2;
        vector<vector<int>>dp(n+1);
        for(i=0;i<=n;i++){
            for(j=0;j<=sum;j++){
                dp[i].push_back(-1);
            }
        }
        return partition(nums,sum,n,dp);
    }
};
