#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int> dist, vector<bool> visited)
{
    int minValue = INT_MAX, j = -1;
    for (int i = 0; i < dist.size(); i++)
    {
        if (visited[i] == false && dist[i] < minValue)
        {
            minValue = dist[i];
            j = i;
        }
    }
    return j;
}

void Prims(vector<vector<int>> edges, vector<int> dist, vector<bool> visited, vector<int> &parent)
{
    int numVisited = 0;
    while (numVisited != edges.size())
    {
        int minNode = findMin(dist, visited);
        visited[minNode] = true;
        numVisited++;
        for (int i = 0; i < edges.size(); i++)
        {
            int wt = edges[minNode][i];
            if (wt != 0 && wt < dist[i] && visited[i] == false)
            {
                dist[i] = edges[minNode][i];
                parent[i] = minNode;
            }
        }
    }
}

int main()
{
    int E, V;
    cin >> E >> V;

    vector<vector<int>> edges(V, vector<int>(V, 0));

    for (int i = 0; i < E; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from][to] = edges[to][from] = weight;
    }

    // distance array
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    vector<bool> visited(V, false);
    vector<int> parent(V);
    parent[0] = -1;

    Prims(edges, dist, visited, parent);

    int weight = 0;

    for (int i = 1; i < parent.size(); i++)
    {
        weight += edges[i][parent[i]];
        cout << i << " " << parent[i] << "\n";
    }

    cout << weight << "\n";

    return 0;
}