#include <bits/stdc++.h>
using namespace std;
#define N 3
int cnt = 0;
struct node
{
    vector<vector<int>> v;
    int f;
    int g;
    node(vector<vector<int>> v, int f, int g) : v(v), f(f), g(g) {}
};
struct cmp
{
    bool operator()(node a, node b)
    {
        if (a.g != b.g)
            return a.f > b.f;
        return a.g > b.g;
    }
};
stack<pair<vector<vector<int>>, int>> path;
map<pair<vector<vector<int>>, int>, pair<vector<vector<int>>, int>> parent;
priority_queue<node, vector<node>, cmp> q;
int heuristicval(vector<vector<int>> cur, vector<vector<int>> goal)
{
    int h = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (cur[i][j] != 0 && cur[i][j] != goal[i][j])
                h++;
        }
    }
    return h;
}
void solve(vector<vector<int>> &initial, vector<vector<int>> final, map<vector<vector<int>>, int> &m)
{
    while (!q.empty())
    {
        vector<vector<int>> temp;
        temp = q.top().v;
        int f = q.top().f;
        int g = q.top().g;
        q.pop();
        m[temp] = 1;
        if (temp == final)
        {
            int f1 = f;
            path.push({temp, f1});
            while (parent[{temp, f1}].first != initial)
            {
                pair<vector<vector<int>>, int> tmp = parent[{temp, f1}];
                path.push(tmp);
                temp = tmp.first;
                f1 = tmp.second;
            }
            path.push({initial, 0});
            return;
        }
        int x, y;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (temp[i][j] == 0)
                {
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        vector<vector<int>> t;
        vector<int> rows = {1, 0, -1, 0};
        vector<int> cols = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nr = rows[i] + x;
            int nc = cols[i] + y;
            if (nr > N - 1 || nc > N - 1 || nr < 0 || nc < 0)
                continue;
            swap(temp[x][y], temp[nr][nc]);
            int f1;
            if (m[temp] != 1)
            {
                cnt++;
                int heu = heuristicval(temp, final);
                f1 = heu + g + 1;
                q.push(node(temp, f1, g + 1));
                t = temp;
            }
            swap(temp[nr][nc], temp[x][y]);
            if (m[t] != 1)
                parent[{t, f1}] = {temp, f};
        }
    }
}

int main()
{
    vector<vector<int>> initial = {{1, 2, 3},
                                   {0, 4, 6},
                                   {7, 5, 8}};
    vector<vector<int>> final = {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 0}};
    map<vector<vector<int>>, int> m;
    q.push(node(initial, 0, 0));
    solve(initial, final, m);
    while (!path.empty())
    {
        vector<vector<int>> t = path.top().first;
        cout << "Cost: " << path.top().second << endl;
        path.pop();
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                cout << t[i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
    cout << "Explored Nodes: " << cnt++;
    return 0;
}