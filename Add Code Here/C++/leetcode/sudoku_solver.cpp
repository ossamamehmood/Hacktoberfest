class Solution {
public:
    bool isvalid(vector<vector<char>>& board, char c, int row_i, int col_i){
        for(int i=0; i<9; ++i){
            if(board[row_i][i]==c) return false;
            else if(board[i][col_i]==c) return false;
            else if(board[3*(row_i/3) + i/3][3*(col_i/3) + i%3]==c) return false;
        }
        return true;
    }
    bool solver(vector<vector<char>>& board, int rstart){
        for(int row=rstart; row<9; ++row){
            for(int col=0; col<9; ++col){
                if(board[row][col]=='.'){
                    for(char c='1'; c<='9'; ++c){
                        if(isvalid(board, c, row, col)){
                            board[row][col] = c;
                            if(solver(board, row)) return true;
                            else board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board, 0);
    }
};
