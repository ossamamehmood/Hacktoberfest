#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        bool answer;

        int rows[9][9] = {0};
        int cols[9][9] = {0};
        int box[9][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    int ch = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;

                    if (rows[i][ch] > 0 || cols[j][ch] > 0 || box[k][ch] > 0)
                        return false;
                    else
                    {
                        rows[i][ch]++;
                        cols[j][ch]++;
                        box[k][ch]++;
                    }
                }
            }
        }

        answer = true;
        return answer;
    }
};
int main()
{

    return 0;
}