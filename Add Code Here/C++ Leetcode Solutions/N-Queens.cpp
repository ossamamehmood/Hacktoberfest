class Solution {
public:
    void solve(int n, vector<vector<string>>& output, vector<string>& temp, int col, vector<int>& leftrow, vector<int>& upperdiagonal, vector<int>& lowerdiagonal) {
        if (col == n) {
            output.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++) {

            if (leftrow[row] == 0 && upperdiagonal[(n - 1) + (col - row)] == 0 && lowerdiagonal[row + col] == 0) {

                temp[row][col] = 'Q';
                leftrow[row] = 1;
                upperdiagonal[(n - 1) + (col - row)] = 1;
                lowerdiagonal[row + col] = 1;


                solve(n, output, temp, col + 1, leftrow, upperdiagonal, lowerdiagonal);


                temp[row][col] = '.';
                leftrow[row] = 0;
                upperdiagonal[(n - 1) + (col - row)] = 0;
                lowerdiagonal[row + col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;      
        vector<string> temp(n, string(n, '.'));       
        vector<int> leftrow(n, 0), upperdiagonal(2 * n - 1, 0), lowerdiagonal(2 * n - 1, 0); 

        solve(n, output, temp, 0, leftrow, upperdiagonal, lowerdiagonal);

        return output;
    }
};
