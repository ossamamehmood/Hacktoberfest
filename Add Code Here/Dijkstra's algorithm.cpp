#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>> > adj; // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graphs
    }

    void dijkstra(int src) {
        vector<int> distance(V, INF);
        distance[src] = 0;

        // Create a min-heap to store vertices with their distances
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});

        while (!minHeap.empty()) {
            int u = minHeap.top().second;
            minHeap.pop();

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                // Relaxation step
                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    minHeap.push({distance[v], v});
                }
            }
        }

        // Print the shortest distances from the source vertex
        cout << "Shortest distances from source " << src << " to all other vertices:" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": " << distance[i] << endl;
        }
    }
};

int main() {
    int V = 6; // Number of vertices
    Graph g(V);

    // Adding edges with weights
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 7);
    g.addEdge(2, 4, 3);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 5);

    int sourceVertex = 0; // Source vertex for Dijkstra's algorithm
    g.dijkstra(sourceVertex);

    return 0;
}
