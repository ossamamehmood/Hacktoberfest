class Solution {
public:
    void bfs(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &vis) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        vis[i][j] = 1;
        q.push({i,j});
        while(!q.empty()) {
            auto node = q.front();
            int x = node.first;
            int y = node.second;
            q.pop();
            for(int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx < 0 or ny < 0 or nx >= n or ny >= m or vis[nx][ny] or grid[nx][ny] == '0')
                    continue;
                q.push({nx,ny});
                vis[nx][ny] = 1;
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' and vis[i][j] == 0) {
                    ans++;
                    bfs(grid, i, j, vis);
                }
            }
        }
        return ans;
    }
};