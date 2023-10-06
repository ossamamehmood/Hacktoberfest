class Solution {
    char[][] mat;
    int[] DIR = {1, 0, -1, 0, 1};
    public int numIslands(char[][] grid) {
        int n = 0;
        mat = grid;
        int rows = mat.length;
        int cols = mat[0].length;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(mat[i][j] == '1') {
                    visitIsland(i, j);
                    n++;
                }
            }
        }
        return n;
    }
    
    public void visitIsland(int r, int c){
        if(r < 0 || c < 0 || r >= mat.length || c >= mat[r].length || mat[r][c] == '0') return;
        mat[r][c] = '0';
        for(int i = 0; i < DIR.length - 1; i++){
            visitIsland(r + DIR[i], c + DIR[i + 1]);
        }
    }
}
