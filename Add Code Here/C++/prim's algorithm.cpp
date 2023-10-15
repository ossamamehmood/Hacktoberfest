#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define a structure to represent an edge in the graph
struct Edge {
    int to, weight;
};

// Define a custom comparison function for the priority queue
struct CompareEdges {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

class Graph {
private:
    int V; // Number of vertices
    vector<vector<Edge>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Function to add an undirected edge to the graph
    void addEdge(int from, int to, int weight) {
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    // Prim's algorithm to find the minimum spanning tree
    void primMST() {
        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX); // Initialize key values to infinity
        vector<int> parent(V, -1);

        priority_queue<Edge, vector<Edge>, CompareEdges> pq;

        // Start with the first vertex as the source
        int src = 0;
        key[src] = 0;
        pq.push({src, 0});

        while (!pq.empty()) {
            int u = pq.top().to;
            pq.pop();

            inMST[u] = true;

            for (const Edge& edge : adj[u]) {
                int v = edge.to;
                int weight = edge.weight;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({v, key[v]});
                    parent[v] = u;
                }
            }
        }

        // Print the minimum spanning tree
        for (int i = 1; i < V; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << endl;
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
    graph.primMST();

    return 0;
}

/*
```
INPUT:
Enter the number of vertices and edges: 
5 7
Enter the edges (from, to, weight):
0 1 2
0 3 8
1 2 3
1 3 6
1 4 5
2 4 7
3 4 9


OUTPUT:
Edge: 0 - 1 Weight: 2
Edge: 1 - 2 Weight: 3
Edge: 1 - 4 Weight: 5
Edge: 0 - 3 Weight: 8

```
*/