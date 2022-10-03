// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

// Simple Approach
// Read Discuss for better ideas

class Solution
{
    int groups;

    int find(int a, int parent[])
    {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent);
    }

    void unite(int a, int b, int parent[], int rank[])
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
                rank[pb]++;
            }
            --groups;
        }
    }

public:
    int removeStones(vector<vector<int>> &stones)
    {
        unordered_map<int, int> mpx, mpy;
        int n = stones.size();
        groups = n;

        int parent[n];
        iota(parent, parent + n, 0);
        int rank[n];
        memset(rank, 0, sizeof(rank));

        for (int i = 0; i < n; ++i)
        {
            int x = stones[i][0], y = stones[i][1];
            if (mpx.find(x) != mpx.end())
                unite(i, mpx[x], parent, rank);
            else
                mpx[x] = i;

            if (mpy.find(y) != mpy.end())
                unite(i, mpy[y], parent, rank);
            else
                mpy[y] = i;
        }

        return n - groups;
    }
};