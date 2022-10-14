class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    
    bool isSafe(vector<vector<char>>& board, int row, int col, char ch) {
        //row validity
        for(int i=0;i<9;i++) {
            if(board[row][i] == ch) {return false;}
        }
        
        //col validity
        for(int i=0;i<9;i++) {
            if(board[i][col] == ch ) {return false;}
        }
        
        //grid validity
        int sr = row - row%3;
        int sc = col - col%3;
        for(int i=0;i<3;i++) 
            for(int j=0;j<3;j++) {
                if(board[sr+i][sc+j] == ch) {return false;}
            }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') {
                    for(char op = '1'; op<='9'; op++) {
                        if(isSafe(board,i,j,op)) {
                            board[i][j] = op;
                            if(solve(board) == true) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};