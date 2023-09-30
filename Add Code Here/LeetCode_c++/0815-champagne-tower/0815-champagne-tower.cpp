class Solution {
public:
    // double solve(int row,int glass,int poured ,
    //  vector<vector<double>>&dp)
    //  {
    //      if( row<0 || glass> row || glass<0)
    //          return 0.00;
         
    //      if( row==0 && glass==0)
    //       return poured;

    //      if(dp[row][glass]!=-1)
    //       return dp[row][glass];

    //      double left = (solve(row-1,glass-1,poured,dp)-1 )/2;
    //      double right =(solve(row-1,glass,poured,dp)-1)/2;

    //      if(left<0)
    //       left=0;
    //      if(right<0)
    //       right=0;

    //       return dp[row][glass]=left+right; 
    //  }
    double champagneTower(int poured, int query_row, int query_glass)  
    {
        // vector<vector<double>>dp(101,vector<double>(101,-1));
        // return min (1.00,solve(query_row,query_glass,poured,dp));

          vector<vector<double>>tower(query_row+1,vector<double>(query_row+1,0.0));
          tower[0][0] =(double)poured;

        //   cout<<tower[0][0];

          for(int row=0;row<query_row;row++)
          {
              for( int glass=0;glass<=row;glass++)
              {
                  double excess = (tower[row][glass]-1.0)/2.0;
                  if( excess>0)
                  {
                      tower[row+1][glass] += excess;
                      tower[row+1][glass+1]+=excess;
                  }
              }
          }
          return min(1.0,tower[query_row][query_glass]);
    }
};