class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1'){
                    n++;
                    visitIsland(grid, i, j);
                }
            }
        }
        return n;
    }
    
private:
    void visitIsland(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        visitIsland(grid, r + 1, c);
        visitIsland(grid, r - 1, c);
        visitIsland(grid, r, c + 1);
        visitIsland(grid, r, c - 1);
    }
};
