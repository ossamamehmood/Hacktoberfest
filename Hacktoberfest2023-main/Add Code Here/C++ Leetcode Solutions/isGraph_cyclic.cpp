#include<bits/stdc++.h>
using namespace std;

// Function to detect cycles using Depth-First Search (DFS)
bool detect(int src, int parent, vector<int> adj[], vector<int> &vis) {
    // Mark the current node as visited
    vis[src] = 1;
    
    // Iterate through all adjacent nodes
    for (auto &child : adj[src]) {
        // If the child node is not visited, recursively check for cycles
        if (!vis[child]) {
            if (detect(child, src, adj, vis) == true) return true;
        } 
        // If the child is visited and not the parent (back edge), a cycle is detected
        else if (child != parent) return true;
    }
    
    // No cycle found in this DFS traversal
    return false;
}

// Function to check if there is any cycle in the graph
bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0); // Initialize a visited array for all vertices
    for (int i = 0; i < V; ++i) {
        // If a vertex is not visited, start DFS from it to detect cycles
        if (!vis[i]) {
            if (detect(i, -1, adj, vis) == true) return true;
        }
    }
    // No cycle found in the entire graph
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V]; // Create an adjacency list representation of the graph
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); // Add edges to the adjacency list
            adj[v].push_back(u); // Since it's an undirected graph, add both directions
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj); // Check for cycles in the graph
        if (ans)
            cout << "1\n"; // If a cycle is detected, output "1"
        else
            cout << "0\n"; // If no cycle is detected, output "0"
    }
    return 0;
}
