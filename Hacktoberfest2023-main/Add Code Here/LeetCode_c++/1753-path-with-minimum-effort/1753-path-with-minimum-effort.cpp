#define p pair<int,pair<int,int>>
class Solution {
public:
    const int dx[4]={-1,0,1,0} , dy[4]={0,1,0,-1};
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<p,vector<p>,greater<p>>pq;

        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));

        dis[0][0] =0;
        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            p curr = pq.top();
             pq.pop();

            int d = curr.first;
            int x = curr.second.first;
            int y = curr.second.second;

            if( x==n-1 && y==m-1)
            return d;

            for( int i=0;i<4;++i)
            {
                int xx = x+dx[i];
                int yy = y+dy[i];

                if( xx<0 ||xx>=n || yy<0 || yy>=m)
                 continue;

                int nd = max( d,abs(heights[xx][yy]-heights[x][y]));
                if( nd < dis[xx][yy] )
                {
                   dis[xx][yy] =nd ;
                   pq.push({ nd,{xx,yy}});
                } 
            } 
        }
        return dis[n-1][m-1];
    }
};