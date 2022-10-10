// Leetcode Question : Rotting Oranges

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>> v= {{0,-1},{1,0},{-1,0},{0,1}};
        
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int time=0;
        while(!q.empty()){
            if(q.front().first!=-1){
                int i= q.front().first;
                int j= q.front().second;
                for(int k=0;k<4;k++){
                    if(v[k][0]+i<0 || v[k][1]+j<0 || v[k][0]+i==m || v[k][1]+j==n){
                        continue;
                    }
                    if(grid[i+v[k][0]][j+v[k][1]] == 1){
                        q.push({i+v[k][0],j+v[k][1]});
                        grid[i+v[k][0]][j+v[k][1]]=2;
                    }
                }
                q.pop();
            }
            else{
                time++;
                q.pop();
                if(q.empty()){
                    break;
                }
                q.push({-1,-1});
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time-1;
    }
};
