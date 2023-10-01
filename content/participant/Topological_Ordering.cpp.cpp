#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Data structure to store a graph edge
struct Edge {
	int src, dest;
};

// A class to represent a graph object
class Graph
{
public:

	// a vector of vectors to represent an adjacency list
	vector<vector<int>> adjList;

	// construct another vector for storing in-degree of the vertices
	vector<int> indegree;

	// Graph Constructor
	Graph(vector<Edge> const &edges, int n)
	{
		// resize the adjacency list to `n` elements of type `vector<int>`
		adjList.resize(n);

		// resize the in-degree vector for `n` vertices
		indegree.resize(n);

		// add edges to the directed graph
		for (auto &edge: edges)
		{
			adjList[edge.src].push_back(edge.dest);

			// increment in-degree of destination vertex by 1
			indegree[edge.dest]++;
		}
	}
};

// Utility function to print contents of a given list
void printPath(list<int> list)		// no ref, no const
{
	while (!list.empty())
	{
		cout << list.front() << ' ';
		list.pop_front();
	}
	cout << endl;
}

// Recursive function to find all topological orderings of a given DAG
void findAllTopologicalOrderings(Graph &graph, auto &path, auto &discovered, int n)
{
	// do for every vertex
	for (int v = 0; v < n; v++)
	{
		// proceed only if the current node's in-degree is 0 and
		// the current node is not processed yet
		if (graph.indegree[v] == 0 && !discovered[v])
		{
			// for every adjacent vertex `u` of `v`, reduce the in-degree of `u` by 1
			for (int u: graph.adjList[v]) {
				graph.indegree[u]--;
			}

			// include the current node in the path and mark it as discovered
			path.push_back(v);
			discovered[v] = true;

			// recur
			findAllTopologicalOrderings(graph, path, discovered, n);

			// backtrack: reset in-degree information for the current node
			for (int u: graph.adjList[v]) {
				graph.indegree[u]++;
			}

			// backtrack: remove the current node from the path and
			// mark it as undiscovered
			path.pop_back();
			discovered[v] = false;
		}
	}

	// print the topological order if all vertices are included in the path
	if (path.size() == n) {
		printPath(path);
	}
}

// Print all topological orderings of a given DAG
void printAllTopologicalOrders(Graph &graph)
{
	// get the total number of nodes in the graph
	int n = graph.adjList.size();

	// create an auxiliary array to keep track of whether a vertex is discovered
	vector<bool> discovered(n);

	// list to store the topological order
	list<int> path;

	// find all topological ordering and print them
	findAllTopologicalOrderings(graph, path, discovered, n);
}

int main()
{
	// vector of graph edges as per the above diagram
	vector<Edge> edges =
	{
		{0, 6}, {1, 2}, {1, 4}, {1, 6}, {3, 0},
		{3, 4}, {5, 1}, {7, 0}, {7, 1}
	};

	// total number of nodes in the graph (labelled from 0 to 7)
	int n = 8;

	// build a graph from the given edges
	Graph graph(edges, n);

	// print all topological ordering of the graph
	printAllTopologicalOrders(graph);

	return 0;
}