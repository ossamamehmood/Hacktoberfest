// First Intuition
// All Pair Shortest Path
// Floydd Warshall
// O(n^3)

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        // create adj matrix
        int adj[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                adj[i][j] = i == j ? 0 : INT_MAX;

        for (auto &e : edges)
        {
            int from = e[0], to = e[1], wt = e[2];
            adj[from][to] = adj[to][from] = wt;
        }

        // floyd warshall
        for (int k = 0; k < n; ++k)         // via node
            for (int i = 0; i < n; ++i)     // source node
                for (int j = 0; j < n; ++j) // dest node
                    if (adj[i][k] == INT_MAX || adj[k][j] == INT_MAX)
                        continue;
                    else
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

        int count, res = INT_MAX, ans = -1;
        for (int i = 0; i < n; ++i)
        {
            count = 0;

            for (int j = 0; j < n; ++j)
                count += i != j && adj[i][j] != -1 && adj[i][j] <= distanceThreshold;

            if (count <= res)
                ans = i, res = count;
        }

        return ans;
    }
};