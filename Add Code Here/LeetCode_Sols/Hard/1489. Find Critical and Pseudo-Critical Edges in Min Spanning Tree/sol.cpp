#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class UnionFind
{
    vector<int> parent;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int pX = find(x);
        int pY = find(y);
        if (pX != pY)
            parent[pX] = pY;
    }
};

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {

        vector<int> critical, pseudo;

        for (int i = 0; i < edges.size(); i++)
        {
            edges[i].push_back(i);
        }

        sort(edges.begin(), edges.end(),
             [](vector<int> &a, vector<int> &b)
             {
                 return a[2] < b[2];
             });

        int mst = getMST(n, edges, -1, -1);

        for (int i = 0; i < edges.size(); i++)
        {
            if (getMST(n, edges, i, -1) > mst)
                critical.push_back(edges[i][3]);
            else if (getMST(n, edges, -1, i) == mst)
                pseudo.push_back(edges[i][3]);
        }

        return {critical, pseudo};
    }

private:
    int getMST(int n, vector<vector<int>> &edges, int block, int include)
    {

        UnionFind uf(n);
        int mst = 0;

        if (include != -1)
        {
            uf.unite(edges[include][0], edges[include][1]);
            mst += edges[include][2];
        }

        for (int i = 0; i < edges.size(); i++)
        {
            if (i == block)
                continue;
            if (uf.find(edges[i][0]) != uf.find(edges[i][1]))
            {
                uf.unite(edges[i][0], edges[i][1]);
                mst += edges[i][2];
            }
        }

        if (uf.find(0) != uf.find(n - 1))
            return INT_MAX;

        return mst;
    }
};

int main()
{

    // call the fn here

    return 0;
}