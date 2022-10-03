// SINGLE SOURCE SHORTEST PATH
// Doesn't work for negative edge weight cycles
// O((V + E)LOG(V))

class Solution
{
public:
    //Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int n, vector<vector<int>> adj[], int S)
    {
        vector<int> dis(n, INT_MAX);
        dis[S] = 0;

        bool vis[n];
        memset(vis, 0, sizeof(vis));

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});

        while (pq.size())
        {
            int node = pq.top().second;
            pq.pop();

            // already visited
            if (vis[node] == true)
                continue;

            // mark as visited as we should not visit it again
            vis[node] = true;

            for (auto &v : adj[node])
            {
                if (vis[v[0]] == false && dis[node] + v[1] < dis[v[0]])
                {
                    dis[v[0]] = dis[node] + v[1];
                    pq.push({dis[v[0]], v[0]});
                }
            }
        }

        return dis;
    }
};