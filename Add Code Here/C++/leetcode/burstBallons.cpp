int solve(vector<int> a,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans=INT_MIN;
        
        for(int k=i;k<=j;k++)
        {
            int x=solve(a,i,k-1,dp)+solve(a,k+1,j,dp)+(a[k]*a[i-1]*a[j+1]);
            ans=max(ans,x);
        }
        
        return dp[i][j]= ans;
    }
    
    int maxCoins(vector<int>& a) {
        
        int n=a.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        a.insert(a.begin(),1);
        a.push_back(1);
        
        //return solve(a,1,n,dp);
        
        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<=n;j++)
            {
                int ans=INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    int x=dp[i][k-1]+dp[k+1][j]+(a[k]*a[i-1]*a[j+1]);
                    ans=max(ans,x);
                }
                
                dp[i][j]=ans;
            }
        }
        
        return dp[1][n];
    }