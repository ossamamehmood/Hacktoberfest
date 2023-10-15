#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Define a structure to represent an edge in the graph
struct Edge {
    int from, to, weight;
};

// Define a custom comparison function to sort edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

class Graph {
private:
    int V; // Number of vertices
    vector<Edge> edges; // List of edges in the graph

public:
    Graph(int vertices) : V(vertices) {}

    // Function to add an undirected edge to the graph
    void addEdge(int from, int to, int weight) {
        edges.push_back({from, to, weight});
    }

    // Kruskal's algorithm to find the minimum spanning tree
    void kruskalMST() {
        vector<Edge> MST; // Store the edges in the MST

        // Sort the edges in ascending order of weight
        sort(edges.begin(), edges.end(), compareEdges);

        // Initialize a disjoint-set data structure
        vector<int> parent(V, -1);

        // Helper function to find the parent of a set (with path compression)
        function<int(int)> find = [&](int v) {
            if (parent[v] == -1)
                return v;
            return parent[v] = find(parent[v]);
        };

        // Helper function to union two sets (with union by rank)
        auto unionSets = [&](int a, int b) {
            int rootA = find(a);
            int rootB = find(b);

            if (rootA != rootB) {
                if (rootA < rootB)
                    parent[rootA] = rootB;
                else
                    parent[rootB] = rootA;
            }
        };

        // Iterate through the sorted edges and add them to the MST
        for (const Edge& edge : edges) {
            int from = edge.from;
            int to = edge.to;

            // Check if adding this edge creates a cycle in the MST
            if (find(from) != find(to)) {
                MST.push_back(edge);
                unionSets(from, to);
            }
        }

        // Print the minimum spanning tree
        cout << "Minimum Spanning Tree:\n";
        for (const Edge& edge : MST) {
            cout << "Edge: " << edge.from << " - " << edge.to << " Weight: " << edge.weight << endl;
        }
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter the edges (from, to, weight):\n";
    for (int i = 0; i < E; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.addEdge(from, to, weight);
    }

    cout << "Minimum Spanning Tree:\n";
    graph.kruskalMST();

    return 0;
}


/*
```
INPUT:
Enter the number of vertices and edges:
6 9
Enter the edges (from, to, weight):
0 1 2
0 2 4
1 2 1
1 3 7
2 3 3
2 4 5
3 4 8
3 5 6
4 5 9


OUTPUT:
Minimum Spanning Tree:
Edge: 1 - 2 Weight: 1
Edge: 0 - 1 Weight: 2
Edge: 2 - 3 Weight: 3
Edge: 2 - 4 Weight: 5
Edge: 3 - 5 Weight: 6

```
*/