#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        // Initialize data structures for disjoint set
        rank.resize(n + 1, 0);  // Rank of each node
        parent.resize(n + 1);   // Parent of each node
        size.resize(n + 1);     // Size of each set

        // set parent as number i and initialize size as 1 for each
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        // Find the parent (representative) of a set containing 'node'.
        if (node == parent[node])
            return node;
        // Path compression: Update the parent to optimize future lookups.
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        // Union two sets by rank (based on rank of the representative).
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) return;

        if (rank[parentU] < rank[parentV]) 
            parent[parentU] = parentV;
        
        else if (rank[parentV] < rank[parentU]) 
            parent[parentV] = parentU;
        
        else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }

    void unionBySize(int u, int v) {
        // Union two sets by size (based on the size of the set).
        int parentU = findParent(u);
        int parentV = findParent(v);

        if (parentU == parentV) return;

        if (size[parentU] < size[parentV]) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
        else {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
    }
};

class Solution
{
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    int Prims(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        // Create a list of edges with their weights and endpoints.
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int adjNode = it[0];
                int weight = it[1];
                int node = i;

                edges.push_back({weight, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        // Sort edges by weight in ascending order.
        sort(edges.begin(), edges.end());
        int mstWeight = 0;
        // Iterate through sorted edges to build the Minimum Spanning Tree.
        for (auto it : edges) {
            int weight = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v)) {
                // Add the edge to the Minimum Spanning Tree.
                mstWeight += weight;
                // Union the two sets.
                ds.unionBySize(u, v);
            }
        }

        return mstWeight;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];
    // Populate the adjacency list with edges and weights.
    for (auto it : edges) {
        vector<int> tmp(2);
        tmp[0] = it[1];
        tmp[1] = it[2];
        adj[it[0]].push_back(tmp);

        tmp[0] = it[0];
        tmp[1] = it[2];
        adj[it[1]].push_back(tmp);
    }

    Solution obj;
    // Find the sum of all edge weights in the Minimum Spanning Tree.
    int mstWeight = obj.Prims(V, adj);
    cout << "*************************KRUSKALS ALGORITHM**************************************" << endl;
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << mstWeight << endl;
    cout << "******************************************************************************" << endl;

    return 0;
}
