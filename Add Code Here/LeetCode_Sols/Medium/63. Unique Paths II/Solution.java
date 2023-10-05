class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0] == 1) return 0;
        int endRow = obstacleGrid.length;
        int endCol = obstacleGrid[0].length;
        int[][] grid = new int[endRow][endCol];
        for(int i = 0; i < endRow; i++){
            if(obstacleGrid[i][0] == 1){
                grid[i][0] = 0;
                break;
            }
            else
                grid[i][0] = 1;
        }
        for(int j = 0; j < endCol; j++){
            if(obstacleGrid[0][j] == 1){
                grid[0][j] = 0;
                break;
            }
            else
                grid[0][j] = 1; 
        }
        for(int i = 1; i < endRow; i++){
            for(int j = 1; j < endCol; j++){
                if(obstacleGrid[i][j] == 1)
                    grid[i][j] = 0;
                else
                    grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }
        }
        return grid[endRow - 1][endCol - 1];
    }
}
