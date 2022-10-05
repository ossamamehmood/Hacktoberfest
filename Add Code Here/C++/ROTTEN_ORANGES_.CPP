
// contributed by: H9660 (www.github.com/H9660)
#include <bits/stdc++.h>

using namespace std;


// the orange that will take the maximum time to rot its nearby oranges will be the answer to the problem.m 
int orangesRotting(vector<vector<int>> &grid)

{

    int n = grid.size();

    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;

    int vis[n][m];

    int cntfresh = 0;

    for (int i = 0; i < n; i++)

    {

        for (int j = 0; j < m; j++)

        {

            if (grid[i][j] == 2)

            {

                q.push({{i, j}, 0});

                vis[i][j] = 2;

            }

            else

            {

                vis[i][j] = 0;

            }

            if (grid[i][j] == 1)

                cntfresh++;

        }

    }

    int tm = 0;

    int drow[] = {-1, 0, 1, 0};

    int dcol[] = {0, 1, 0, -1};

    int cnt = 0;

    while (!q.empty())

    {

        int r = q.front().first.first;

        int c = q.front().first.second;

        int t = q.front().second;   // the previous greatest time

        tm = max(tm, t);

        q.pop();

        for (int i = 0; i < 4; i++)

        {

            int nrow = r + drow[i];

            int ncol = c + dcol[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)

            {

                q.push({{nrow, ncol}, t + 1});

                vis[nrow][ncol] = 2;

                cnt++;

            }

        }

    }

    if (cnt != cntfresh)

        return -1;

    return tm;

}



int main()

{

    vector<vector<int>> grid = {{0, 1, 2}, {0, 1, 2}, {2, 1, 1}};

    cout << orangesRotting(grid) << endl;

    return 0;

}

// there are in total 4*m*n traversals in the worst case so the time complexity is O(4*m*n)
// space complexity is O(M*N)