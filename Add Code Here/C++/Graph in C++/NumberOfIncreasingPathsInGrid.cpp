int n,m,ans = 0,mod = 1e9+7;
using vvi = vector<vector<int>>;
vector<int>  dx{0,0,1,-1}, dy{1,-1,0,0};
int dfs(int i,int j,vvi& grid,vvi& dp){
    if(dp[i][j]!=1) return dp[i][j];
    int count = 1;
    for(int k = 0;k<4;k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x<0 || y<0 || y>=m || x>=n)continue;
        if(grid[x][y]>grid[i][j]) count = (count+dfs(x,y,grid,dp))%mod;
    }
    return dp[i][j] = count;
}
int countPaths(vector<vector<int>>& grid) {
    n = grid.size(),m = grid[0].size();
    vvi dp(n,vector(m,1));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++) 
            ans = (ans + dfs(i,j,grid,dp))%mod;
    return ans;
}
