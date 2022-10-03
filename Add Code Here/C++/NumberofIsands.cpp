class Solution {
public:
    bool isvalid(int x,int y,int rows,int cols,vector<vector<char>>&grid)
    {
        if(x<0 || x>=rows || y<0 || y>=cols || grid[x][y]!='1')
            return false;
        return true;
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int ans=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(grid[i][j]=='1')
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]=='2';
                    while(!q.empty())
                    {
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        int dx[]={-1,0,1,0};
                        int dy[]={0,1,0,-1};
                        for(int k=0;k<4;k++)
                        {
                            int X=x+dx[k];
                            int Y=y+dy[k];
                            if(isvalid(X,Y,rows,cols,grid))
                            {
                                q.push({X,Y});
                                grid[X][Y]='2';
                            }
                        }
                    }
                    ans++;
                }
            }
        }
        return ans;
    }
};