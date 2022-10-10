#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // A vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Total number of nodes in the graph
    int n;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold `n` elements of type `vector<int>`
        this->n = n;
        adjList.resize(n);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Perform DFS on the graph starting from vertex `v`
bool DFS(Graph const &graph, int v, vector<bool> &discovered, vector<int> &color)
{
    // do for every edge (v, u)
    for (int u: graph.adjList[v])
    {
        // if vertex `u` is explored for the first time
        if (!discovered[u])
        {
            // mark the current node as discovered
            discovered[u] = true;
 
            // current node has the opposite color of that its parent
            color[u] = !color[v];
 
            // if DFS on any subtree rooted at `v` returns false
            if (!DFS(graph, u, discovered, color)) {
                return false;
            }
        }
 
        // if the vertex has already been discovered and the color of the vertex
        // `u` and `v` are the same, then the graph is not bipartite
        else if (color[v] == color[u]) {
            return false;
        }
    }
 
    return true;
}
 
// Function to check if a graph is Bipartite using DFS
bool isBipartite(Graph const &graph)
{
    // to keep track of whether a vertex is discovered or not
    vector<bool> discovered(graph.n);
 
    // keep track of the color assigned (0 or 1) to each vertex in DFS
    vector<int> color(graph.n);
 
    // start from any node as the graph is connected and undirected
    int src = 0;
 
    // mark the source vertex as discovered and set its color to 0
    discovered[src] = true, color[src] = 0;
 
    // call DFS procedure
    return DFS(graph, src, discovered, color);
}
 
int main()
{
    // vector of graph edges
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {1, 7}, {2, 3}, {3, 5}, {4, 6}, {4, 8}, {7, 8}, {1, 3}
        // if we remove (1, 3) edge, the graph becomes bipartite
    };
 
    // total number of nodes in the graph (0 to 8)
    int n = 9;
 
    // build a graph from the given edges
    Graph graph(edges, n);
 
    if (isBipartite(graph)) {
        cout << "Graph is bipartite";
    }
    else {
        cout << "Graph is not bipartite";
    }
 
    return 0;
}
