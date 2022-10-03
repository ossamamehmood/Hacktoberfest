// UNION FIND IMPLEMENTATION
// UF -> HELPS IN DETECTING CYCLES VERY FAST
// Greedy take edges of min size, if edge forms cycle, ignore it otherwise add to sum

class Solution
{

    int find(int a, int p[])
    {
        return p[a] == a ? a : p[a] = find(p[a], p);
    }

    bool unite(int a, int b, int parent[], int rank[])
    {
        int pa = find(a, parent), pb = find(b, parent);
        if (pa != pb)
        {
            if (rank[pa] < rank[pb])
                parent[pa] = pb;
            else if (rank[pa] > rank[pb])
                parent[pb] = pa;
            else
            {
                parent[pa] = pb;
                ++rank[pb];
            }

            return true;
        }
        return false;
    }

public:
    int spanningTree(int n, vector<vector<int>> adj[])
    {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> edges;

        for (int from = 0; from < n; ++from)
            for (auto &to : adj[from])
                edges.push({to[1], from, to[0]});

        // union find init
        int parent[n], rank[n];
        memset(rank, 0, sizeof(rank));
        iota(parent, parent + n, 0);

        int sum = 0, num = 0;

        while (true)
        {
            int wt = edges.top()[0], from = edges.top()[1], to = edges.top()[2];
            edges.pop();

            if (unite(from, to, parent, rank)) // returns true if edge not forming cycle
            {
                sum += wt;

                if (++num == n - 1)
                    break;
            }
        }

        return sum;
    }
};