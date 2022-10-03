// SIMPLE BFS

void minDistance(int src, int n, vector<int> adj[])
{
    // init distance array
    int dist[n];
    for (int i = 0; i < n; ++i)
        dist[i] = INT_MAX;

    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (q.size())
    {
        int node = q.front();
        q.pop();

        for (auto &i : adj[node])
        {
            if (dist[node] + 1 < dist[i])
            {
                dist[i] = dist[node] + 1;
                queue.push(dist[i]);
            }
        }
    }

    // print distances
    for (auto &d : dist)
        cout << d << " ";
}