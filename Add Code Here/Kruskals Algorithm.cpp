#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Edge {
    int from, to, weight;
};


struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) {
            return false; 
        }

        if (rank[x] < rank[y]) {
            swap(x, y);
        }

        parent[y] = x;

        if (rank[x] == rank[y]) {
            rank[x]++;
        }

        return true;
    }
};


vector<Edge> kruskal(vector<Edge>& edges, int n) {
    vector<Edge> minSpanTree;
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DisjointSet dsu(n);

    for (const Edge& edge : edges) {
        if (dsu.unite(edge.from, edge.to)) {
            minSpanTree.push_back(edge);
        }
    }

    return minSpanTree;
}

int main() {
    int n, m; 
    cin >> n >> m;

    vector<Edge> edges;

    
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back({u, v, weight});
    }

    vector<Edge> minSpanTree = kruskal(edges, n);

    
    for (const Edge& edge : minSpanTree) {
        cout << "Edge: " << edge.from << " - " << edge.to << " Weight: " << edge.weight << endl;
    }

    return 0;
}
