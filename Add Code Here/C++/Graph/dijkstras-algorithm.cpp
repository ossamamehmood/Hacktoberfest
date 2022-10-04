#include <iostream>
#include <vector>
using namespace std;

// Time Complexity : O(V^2)
// Can be improved if -
//      1. We use adjacency list
//      2. We use minHeap in 'findMin' function

int findMin(vector<int> distance, vector<int> visited)
{
    int minNode = INT_MAX, vertex = -1;
    for (int i = 0; i < distance.size(); i++)
    {
        if (!visited[i] && distance[i] < minNode)
        {
            minNode = distance[i];
            vertex = i;
        }
    }
    return vertex;
}

void Dijkstra(vector<vector<int>> edges)
{
    int V = edges.size();

    vector<int> parent(V, -1), distance(V, INT_MAX), visited(V, 0);
    distance[0] = 0;

    // as we require only V-1 vertices
    for (int i = 0; i < V - 1; i++)
    {
        int minNode = findMin(distance, visited);
        visited[minNode] = 1;

        // relax all adjacent edges
        for (int j = 0; j < V; j++)
        {
            int wt = edges[minNode][j];
            if (!visited[j] && wt != 0 && distance[minNode] != INT_MAX && distance[minNode] + wt < distance[j])
            {
                distance[j] = distance[minNode] + wt;
                parent[j] = minNode;
            }
        }
    }

    cout << "ans \n";
    for (int i = 1; i < parent.size(); i++)
    {
        cout << "edge: " << i << "---" << parent[i] << "  distance of " << i << " from source: " << distance[i] << "\n";
    }
}

int main()
{
    int E, V;
    cin >> E >> V;

    vector<vector<int>> edges(V, vector<int>(V, 0));
    for (int i = 0; i < E; i++)
    {
        int from, to, wt;
        cin >> from >> to >> wt;
        edges[from][to] = wt;
        edges[to][from] = wt;
    }

    Dijkstra(edges);
}