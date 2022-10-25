class Solution {
public:
    long long solver(vector<int> &jobDifficulty,int d,int i,vector<vector<int>> &dp){
        if(i==jobDifficulty.size() and d==0){
            return 0;
        }else if(i==jobDifficulty.size() or d==0 or jobDifficulty.size()-i<d){
            return INT_MAX;
        }
        
        if(dp[i][d]!=-1) return dp[i][d];
        long long ans=INT_MAX;
        int maxi=0;
        for(int index=i;index<jobDifficulty.size();index++){
            maxi=max(maxi,jobDifficulty[index]);
            ans=min(ans,maxi+solver(jobDifficulty,d-1,index+1,dp));
        }
        return dp[i][d]=ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
          vector<vector<int>> dp(jobDifficulty.size(),vector<int>(d+1,-1));
          int ans=solver(jobDifficulty,d,0,dp);
          return d>jobDifficulty.size()?-1:ans;
    }
};