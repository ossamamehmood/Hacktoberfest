#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the sum of weights of edges of the Minimum Spanning Tree.
    int findMinimumSpanningTreeWeight(int V, vector<vector<int>> adj[])
    {
        // Create a priority queue to store edge weights and corresponding nodes.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Create a vector to track visited nodes.
        vector<int> visited(V, 0);

        // Initialize the priority queue with the starting node (node 0) and weight 0.
        pq.push({0, 0});

        // Initialize the sum of edge weights.
        int sum = 0;

        // Process edges until the priority queue is empty.
        while (!pq.empty()) {
            // Get the edge with the smallest weight.
            auto edge = pq.top();
            pq.pop();

            // Extract the node and weight from the edge.
            int node = edge.second;
            int weight = edge.first;

            // If the node is already visited, skip it.
            if (visited[node] == 1)
                continue;

            // Add the node to the Minimum Spanning Tree (MST).
            visited[node] = 1;
            sum += weight;

            // Explore adjacent nodes and add their edges to the priority queue.
            for (auto neighbor : adj[node]) {
                int adjNode = neighbor[0];
                int edgeWeight = neighbor[1];

                // If the neighbor is not visited, add its edge to the priority queue.
                if (!visited[adjNode]) {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        // Return the sum of all edge weights in the Minimum Spanning Tree.
        return sum;
    }
};

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>> adj[V];

    // Populate the adjacency list with edges and weights.
    for (auto edge : edges) {
        vector<int> tmp(2);
        tmp[0] = edge[1];
        tmp[1] = edge[2];
        adj[edge[0]].push_back(tmp);

        tmp[0] = edge[0];
        tmp[1] = edge[2];
        adj[edge[1]].push_back(tmp);
    }

    Solution obj;
    // Find the sum of all edge weights in the Minimum Spanning Tree.
    int sum = obj.findMinimumSpanningTreeWeight(V, adj);
    cout << "*************************PRIMS ALGORITHM**************************************" << endl;
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << sum << endl;
    cout << "******************************************************************************" << endl;
    return 0;
}
