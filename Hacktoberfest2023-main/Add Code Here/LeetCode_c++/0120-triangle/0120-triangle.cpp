class Solution {
public:
    int solve( vector<vector<int>>&triangle,int j ,int i)
    {
        if(i== triangle.size())
         return 0;
        int sum0 =INT_MAX;
        int sum1 =INT_MAX;
      
        sum0 = triangle[i][j] + solve(triangle,j,i+1);
         if( j+1 < triangle[i].size())
        sum1 = triangle[i][j+1] + solve(triangle,j+1,i+1);

        return min(sum0,sum1);
    }
    int solvemem( vector<vector<int>>&triangle,int j,int i,vector<vector<int>>&dp)
    {
      if(i== triangle.size())
         return 0;
      if(dp[i][j]!=-1)
         return dp[i][j];

        int sum0 =INT_MAX;
        int sum1 =INT_MAX;
      
        sum0 = triangle[i][j] + solvemem(triangle,j,i+1,dp);
         if( j+1 < triangle[i].size())
        sum1 = triangle[i][j+1] + solvemem(triangle,j+1,i+1,dp);

        return dp[i][j] =min(sum0,sum1);
    }
     
    int solvetb( vector<vector<int>>&triangle )
    {
       int n = triangle.size();
       vector<vector<int>>dp( n,vector<int>( n+1,0));

       for(int i=0;i<n;i++ )
        dp[n-1][i] = triangle[n-1][i];

       for( int i = n-2 ;i>=0;i--)
       {
           for( int j= 0;j<i+1;j++)
           {
                int sum0 =INT_MAX;
                int sum1 =INT_MAX;
            
                sum0 = triangle[i][j] + dp[i+1][j];
                sum1 = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] =min(sum0,sum1);
           }
       } 
       return dp[0][0];

    } 
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        // return solve( triangle ,0,0 );

        // vector<vector<int>>dp(triangle.size(),vector<int>(triangle.size(),-1));
        // return solvemem( triangle,0,0,dp);

        return solvetb( triangle );
    }
};