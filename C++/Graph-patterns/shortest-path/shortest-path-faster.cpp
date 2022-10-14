// SIMILAR TO BELLMAN FORD
// USES THE QUEUE DATA STRUCTURE
// WE DO NOT RELAX EVERY VERTEX EACH TIME
// WE ONLY ADD THE RELAXED VERTICES TO THE QUEUE
// THEN WE POP OUT AND RELAX ADJACENT VERTICES

void spf(int n, int src, vector<vector<int>> adj[])
{
    // init distance array
    int dis[n];
    for (int i = 0; i < n; ++i)
        dis[i] = INT_MAX;
    dis[src] = 0;

    // init inqueue bool array
    bool inq[n];
    memset(inq, 0, sizeof(inq));

    queue<int> q;
    q.push(src);
    inq[src] = true;

    while (q.size())
    {
        int node = q.front();
        q.pop();
        inq = false;

        for (auto &i : adj[node])
        {
            int from = node, to = i[0], wt = i[1];
            if (dis[from] + wt < dis[to])
            {
                dis[to] = dis[from] + wt;
                if (inq[to] == false)
                    q.push(to), inq[to] = true;
            }
        }
    }

    // print distances
    for (auto &i : dis)
        cout << i << " ";
}
