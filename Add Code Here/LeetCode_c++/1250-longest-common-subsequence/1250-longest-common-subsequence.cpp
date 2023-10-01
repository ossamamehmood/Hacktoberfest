class Solution {
public:
    int solve(string text1, string text2,int i1,int i2)
    {
        if(i1>=text1.size() || i2>=text2.size())
         return 0;

        if( text1[i1]==text2[i2])
         return 1+ solve(text1,text2,i1+1,i2+1);

        else 
          return max(solve(text1,text2,i1+1,i2),
                      solve(text1,text2,i1,i2+1));  
        
    }

    int solvemem(string &text1, string &text2,int i1,int i2,
     vector<vector<int>>&dp)
    {
        if(i1>=text1.size() || i2>=text2.size())
         return 0;

        if(dp[i1][i2]!=-1)
         return dp[i1][i2];

        if( text1[i1]==text2[i2])
         return dp[i1][i2] =1+ solvemem(text1,text2,i1+1,i2+1,dp);

        else 
          return dp[i1][i2] = max(solvemem(text1,text2,i1+1,i2,dp),
                      solvemem(text1,text2,i1,i2+1,dp));  
        
    }

    int solvetab(string &text1, string &text2 )
    {
         int n1 = text1.size();
         int n2 = text2.size();

         vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for( int i1=n1-1;i1>=0;i1--)
        {
            for( int i2=n2-1;i2>=0;i2--)
            {
            if( text1[i1]==text2[i2])
                 dp[i1][i2] =1+ dp[i1+1][i2+1];
            else 
                 dp[i1][i2] = max(dp[i1+1][i2],dp[i1][i2+1]);  
            }
        }
     return dp[0][0];  
    }

    int longestCommonSubsequence(string text1, string text2) 
    {
    //    return solve(text1,text2,0,0); 

    //    int n1 = text1.size();
    //    int n2 = text2.size();

    //    vector<vector<int>>dp(n1,vector<int>(n2,-1));
    //     return solvemem(text1,text2,0,0,dp);

          return solvetab(text1,text2);

    }
};