class Solution {
    public boolean isValidSudoku(char[][] board) {
        for(int i = 0; i < 9; i++){
            Set<Character> row = new HashSet<Character>();
            Set<Character> col = new HashSet<Character>();
            Set<Character> sqr = new HashSet<Character>();
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.' && !row.add(board[i][j])) return false;
                if(board[j][i] != '.' && !col.add(board[j][i])) return false;
                int rowIdx = 3*(i/3);
                int colIdx = 3*(i%3);
                if(board[rowIdx + j/3][colIdx + j%3] != '.' && !sqr.add(board[rowIdx + j/3][colIdx + j%3])) return false;
            }
        }
        return true;
    }
}
