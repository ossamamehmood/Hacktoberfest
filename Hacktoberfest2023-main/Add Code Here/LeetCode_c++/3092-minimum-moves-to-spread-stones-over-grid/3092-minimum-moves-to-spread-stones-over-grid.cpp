class Solution {
public:
    bool check(vector<vector<int>> &grid)
    {
        for(int i=0;i<3;i++)
        {
            for( int j=0;j<3;j++)
            {
                if(grid[i][j]!=1)
                 return 0;
            }
        }
        return true;
    }
    int helper( vector<vector<int>>&grid)
    {
        if(check(grid))
         return 0;

        int ans =INT_MAX;
        for( int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if( grid[i][j]==0 )
                {
                    grid[i][j]=1;

                    for( int ii=0;ii<3;ii++)
                    {
                        for( int jj=0;jj<3;jj++)
                        {
                            if( grid[ii][jj]>1)
                            {
                                grid[ii][jj]-=1;
                                ans = min( ans, abs(ii-i)+abs(jj-j)+ helper(grid) );
                                grid[ii][jj]+=1;
                            }
                        }
                    }
                    grid[i][j]=0;
                }
            }
        } 
        return ans;
    }
    int minimumMoves(vector<vector<int>>& grid) 
    {
      return helper(grid);   
    }
};