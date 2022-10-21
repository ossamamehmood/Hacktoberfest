class Solution
{
    int findMin(vector<int> vis, vector<int> distance, int n)
    {
        int minV = INT_MAX, vertex = -1;
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i] && distance[i] < minV)
            {
                minV = distance[i];
                vertex = i;
            }
        }
        return vertex;
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // create adj matrix
        vector<vector<int>> adj(n + 1, vector<int>(n + 1, -1));
        for (auto i : times)
            adj[i[0]][i[1]] = i[2];

        vector<int> vis(n + 1, 0), distance(n + 1, INT_MAX);
        distance[k] = 0;
        int visited = 0;

        while (visited < n)
        {
            int minNode = findMin(vis, distance, n);
            if (minNode == -1)
                return -1;
            vis[minNode] = 1;
            visited++;

            for (int i = 1; i <= n; i++)
            {
                int d = adj[minNode][i];
                if (!vis[i] && distance[minNode] != INT_MAX && d != -1 && distance[minNode] + d < distance[i])
                {
                    distance[i] = distance[minNode] + d;
                }
            }
        }

        int maxTime = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (maxTime < distance[i])
                maxTime = distance[i];
        }

        return maxTime;
    }
};