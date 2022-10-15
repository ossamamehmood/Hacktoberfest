#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix)
{
    vector<int> ans;

    if (matrix.size() == 0)
        return ans;

    int R = matrix.size(), C = matrix[0].size();
    vector<vector<bool> > seen(R, vector<bool>(C, false));
    int dr[] = { 0, 1, 0, -1 };
    int dc[] = { 1, 0, -1, 0 };
    int r = 0, c = 0, di = 0;
    for (int i = 0; i < R * C; i++) {
        ans.push_back(matrix[r]);
        seen[r] = true;
        int cr = r + dr[di];
        int cc = c + dc[di];

        if (0 <= cr && cr < R && 0 <= cc && cc < C
            && !seen[cr][cc]) {
            r = cr;
            c = cc;
        }
        else {
            di = (di + 1) % 4;
            r += dr[di];
            c += dc[di];
        }
    }
    return ans;
}

// Driver code
int main()
{
    vector<vector<int> > a{ { 1, 2, 3, 4 },
                            { 5, 6, 7, 8 },
                            { 9, 10, 11, 12 },
                            { 13, 14, 15, 16 } };

    for (int x : spiralOrder(a)) {
        cout << x << " ";
    }
    return 0;
}
