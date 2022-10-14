class Solution
{

    bool bfs(int node, vector<int> adj[], int color[])
    {
        color[node] = 1;

        queue<int> q;
        q.push(node);

        while (q.size())
        {
            int i = q.front();
            q.pop();

            for (auto &c : adj[i])
            {
                if (color[c] == -1)
                {
                    color[c] = 1 - color[i];
                    q.push(c);
                }
                else if (color[c] == color[i])
                    return false;
            }
        }

        return true;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> adj[n + 1];

        for (auto &d : dislikes)
        {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        int color[n + 1];
        memset(color, -1, sizeof(color));

        for (int i = 1; i <= n; ++i)
        {
            if (color[i] == -1 && bfs(i, adj, color) == false)
                return false;
        }

        return true;
    }
};