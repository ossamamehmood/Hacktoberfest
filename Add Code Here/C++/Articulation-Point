// C++ program to find articulation points in an undirected
// graph
#include <bits/stdc++.h>
using namespace std;

// A recursive function to traverse the graph without
// considering the ith vertex and its associated edges
void dfs(vector<int> adj[], int V, vector<int>& vis,
		int i, int curr)
{
	vis[curr] = 1;
	for (auto x : adj[curr]) {
		if (x != i) {
			if (!vis[x]) {
				dfs(adj, V, vis, i, x);
			}
		}
	}
}

// Function to find Articulation Points in the graph
void AP(vector<int> adj[], int V)
{

	// Iterating over all the vertices and for each vertex i
	// remove the vertex and check whether the graph remains
	// connected.
	for (int i = 1; i <= V; i++) {

		// To keep track of number of components of graph
		int components = 0;

		// To keep track of visited vertices
		vector<int> vis(V + 1, 0);

		// Iterating over the graph after removing vertex i
		// and its associated edges
		for (int j = 1; j <= V; j++) {
			if (j != i) {

				// If the jth vertex is not visited it will
				// form a new component.
				if (!vis[j]) {

					// Increasing the number of components.
					components++;

					// dfs call for the jth vertex
					dfs(adj, V, vis, i, j);
				}
			}
		}
		// If number of components is more than 1 after
		// removing the ith vertex then vertex i is an
		// articulation point.
		if (components > 1) {
			cout << i << "\n";
		}
	}
}

// Utility function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

// Driver Code
int main()
{
	// Create graphs given in above diagrams
	cout << "Articulation points in the graph \n";
	int V = 5;
	vector<int> adj1[V + 1];
	addEdge(adj1, 1, 2);
	addEdge(adj1, 2, 3);
	addEdge(adj1, 1, 3);
	addEdge(adj1, 3, 4);
	addEdge(adj1, 4, 5);
	AP(adj1, V);

	return 0;
}
