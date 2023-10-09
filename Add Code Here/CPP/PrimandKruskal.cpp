#include <bits/stdc++.h>
using namespace std;
 
// Number of vertices in the graph
#define V 5
 
// A function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}
 
// A utility function to print the
// constructed MST stored in parent[]
void printMST(int parent[], int graph[V][V])
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
}
 
// Function to construct and print MST using adjacency
// matrix representation
void primMST(int graph[V][V])
{
    // Array to store constructed MST
    int parent[V];
 
    // Key values used to pick minimum weight edge in cut
    int key[V];
 
    // To represent set of vertices included in MST
    bool mstSet[V];
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;
 
    key[0] = 0;
   
    // First node is always root of MST
    parent[0] = -1;
 
    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {
         
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
 
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
 
        // Update key value and parent index of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 
            // graph[u][v] is non zero only for adjacent vertices of m mstSet[v] is false for vertices
            if (graph[u][v] && mstSet[v] == false
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
 
    // Print the constructed MST
    printMST(parent, graph);
}
 
// Driver's code
int main()
{
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
 
    // Print the solution
    primMST(graph);
 
    return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

// Define a structure to represent an edge with weight.
struct Edge {
    int from;
    int to;
    int weight;
};

// Define a structure to represent a disjoint-set.
struct DisjointSet {
    vector<int> parent;
    vector<int> rank;
};

// Function to initialize the disjoint-set data structure.
void initializeSets(DisjointSet &sets, int n) {
    sets.parent.resize(n);
    sets.rank.resize(n);
    for (int i = 0; i < n; i++) {
        sets.parent[i] = i;
        sets.rank[i] = 0;
    }
}

// Function to find the root of a set using path compression.
int findSet(DisjointSet &sets, int i) {
    if (i != sets.parent[i])
        sets.parent[i] = findSet(sets, sets.parent[i]);
    return sets.parent[i];
}

// Function to perform union of two sets based on rank.
void unionSets(DisjointSet &sets, int i, int j) {
    int root1 = findSet(sets, i);
    int root2 = findSet(sets, j);
    if (root1 != root2) {
        if (sets.rank[root1] < sets.rank[root2])
            sets.parent[root1] = root2;
        else if (sets.rank[root1] > sets.rank[root2])
            sets.parent[root2] = root1;
        else {
            sets.parent[root2] = root1;
            sets.rank[root1]++;
        }
    }
}

// Function to compare edges based on weight for sorting.
bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm.
vector<Edge> kruskalMST(vector<Edge> &edges, int numVertices) {
    vector<Edge> MST; // Stores the minimum spanning tree.
    DisjointSet sets;
    initializeSets(sets, numVertices);
    
    sort(edges.begin(), edges.end(), compareEdges); // Sort edges by weight.

    for (const Edge &edge : edges) {
        int root1 = findSet(sets, edge.from);
        int root2 = findSet(sets, edge.to);
        
        if (root1 != root2) {
            MST.push_back(edge);
            unionSets(sets, root1, root2);
        }
    }
    
    return MST;
}

int main() {
    int numVertices = 5;
    vector<Edge> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    vector<Edge> minSpanningTree = kruskalMST(edges, numVertices);

    // Print the minimum spanning tree.
    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const Edge &edge : minSpanningTree) {
        cout << edge.from << " - " << edge.to << " \tWeight: " << edge.weight << endl;
    }

    return 0;
}
