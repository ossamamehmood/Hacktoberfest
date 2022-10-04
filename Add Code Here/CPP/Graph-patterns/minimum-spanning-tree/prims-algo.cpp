// Prim's Algorithm
// SELECT MIN DISTANCE AT EACH POINT, RELAX ADJ NODES IF THEY'RE NOT VISITED
// TOTAL EDGES REQ ==> N - 1

class Solution
{
public:
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        int dis[n], vis[n];
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i)
            dis[i] = INT_MAX;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dis[0] = 0;
        pq.push({0, 0});

        int num = 0;

        while (num != n - 1)
        {
            int node = pq.top().second, wt = pq.top().first;
            pq.pop();

            if (vis[node] == true)
                continue;
            vis[node] = true;
            ++num;

            for (auto &v : adj[node])
            {
                if (vis[v[0]] == false && dis[v[0]] > v[1])
                {
                    dis[v[0]] = v[1];
                    pq.push({dis[v[0]], v[0]});
                }
            }
        }

        return accumulate(dis, dis + n, 0);
    }
};
