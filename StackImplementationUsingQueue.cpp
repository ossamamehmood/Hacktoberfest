#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int numIslands = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    numIslands++;
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    while (!s.empty()) {
                        pair<int, int> curr = s.top();
                        s.pop();
                        int x = curr.first;
                        int y = curr.second;
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                            grid[x][y] = '0';
                            s.push({x - 1, y});
                            s.push({x + 1, y});
                            s.push({x, y - 1});
                            s.push({x, y + 1});
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};
