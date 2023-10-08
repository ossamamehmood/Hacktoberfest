
// Prim's Algorithm in CPP

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 6

int minKey(int key[], bool mst[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mst[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}


void print(int parent[], int G[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< G[i][parent[i]] << " \n";
}

void prim(int G[V][V])
{
	int parent[V];
    int key[V];
    bool mst[V];

	for (int i = 0; i < V; i++)
    {
		key[i] = INT_MAX, mst[i] = false;
    }  

	key[0] = 0;

	// First node is always root of MST
	parent[0] = -1;

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++) {
		int u = minKey(key, mst);
        mst[u] = true;
        for (int v = 0; v < V; v++)
        {
              if (G[u][v] && mst[v] == false
				&& G[u][v] < key[v])
				parent[v] = u, key[v] = G[u][v];
        }
	}

	// Print the constructed MST
	print(parent, G);
}


int main()
{
	int G[V][V] = { { 0, 4, 6, 0, 0, 0},
						{ 4, 0, 6, 3, 4, 0 },
						{ 6, 6, 0, 1, 8, 0 },
						{ 0, 3, 1, 0, 2, 3 },
						{ 0, 4, 8, 2, 0, 7},
                        { 6, 0, 0, 3, 7, 0} };

	prim(G);
    return 0;
}




*************************************************************************************************************************************************************************************************************************************************




// Kruskal's Algorithm for graphs in Cpp

#include <bits/stdc++.h>
using namespace std;

#define V 5
int parent[V];


int search(int i)
{
	while (parent[i] != i)
		i = parent[i];
	return i;
}
void union1(int i, int j)
{
	int a = search(i);
	int b = search(j);
	parent[a] = b;
}

// Finds MST using Kruskal's algorithm
void kruskal(int cost[][V])
{
	int mincost = 0; // Cost of min MST.

	// Initialize sets of disjoint sets.
	for (int i = 0; i < V; i++)
		parent[i] = i;

	// Include minimum weight edges one by one
	int count = 0;
	while (count < V - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (search(i) != search(j) && cost[i][j] < min) {
					min = cost[i][j];
					a = i;
					b = j;
				}
			}
		}
    union1(a, b);
		printf("Edge %d:(%d, %d) cost:%d \n",
			count++, a, b, min);
		mincost += min;
	}
	printf("\n Minimum cost= %d \n", mincost);
}
int main()
{
	int cost[][V] = {
		{ INT_MAX, 4, INT_MAX, 10, INT_MAX },
		{ 1, INT_MAX, 2, 7, 9 },
		{ INT_MAX, 4, INT_MAX, INT_MAX, 11 },
		{ 3, 6, INT_MAX, INT_MAX, 5 },
		{ INT_MAX, 2, 1, 10, INT_MAX },
	};
  kruskal(cost);
  return 0;
}

