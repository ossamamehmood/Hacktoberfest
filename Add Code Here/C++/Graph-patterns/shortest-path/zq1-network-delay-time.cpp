// DIJKSTRA'S ALGORITHM

class Solution
{
    void create_adj_list(vector<vector<int>> &times, vector<pair<int, int>> adj[])
    {
        for (auto &t : times)
            adj[t[0]].push_back({t[1], t[2]});
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // init
        int dis[n + 1];
        bool vis[n + 1];
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= n; ++i)
            dis[i] = INT_MAX;

        vector<pair<int, int>> adj[n + 1];
        create_adj_list(times, adj);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // begin
        dis[k] = 0;
        pq.push({0, k});

        while (pq.size())
        {
            int node = pq.top().second, wt = pq.top().first;
            pq.pop();

            if (vis[node] == true)
                continue;

            vis[node] = true;

            for (auto &v : adj[node])
                if (wt + v.second < dis[v.first])
                {
                    dis[v.first] = wt + v.second;
                    pq.push({dis[v.first], v.first});
                }
        }

        int max_time = *max_element(dis + 1, dis + n + 1);
        return max_time == INT_MAX ? -1 : max_time;
    }
};