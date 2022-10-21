#include <iostream>
#include <vector>
using namespace std;

struct edge
{
    int src, dst, wt;
};

int BellmanFord(int V, vector<edge> Edges)
{
    int E = Edges.size();
    vector<int> parent(V, -1), distance(V, INT_MAX);
    distance[0] = 0; // assuming source = node 0
    bool updated;

    // relax V-1 times
    for (int i = 0; i < V - 1; i++)
    {
        updated = false; // flag

        // relax all edges
        for (int j = 0; j < E; j++)
        {
            edge e = Edges[j];
            if (distance[e.src] != INT_MAX && distance[e.src] + e.wt < distance[e.dst])
            {
                updated = true;
                distance[e.dst] = distance[e.src] + e.wt;
                parent[e.dst] = e.src;
            }
        }

        if (updated == false)
            break;
    }

    // check for vth time
    for (int i = 0; i < E && updated == true; i++)
    {
        edge e = Edges[i];
        if (distance[e.src] != INT_MAX && distance[e.src] + e.wt < distance[e.dst])
            return 1;
    }

    // if no update in vth iteration
    // or 2 consecutive distance arrays have same values
    // therefore no cycle
    // print edges
    cout << "\nThe given graph has no negative edge weight cycle \n";
    for (int i = 1; i < V; i++)
        cout << "src: " << parent[i] << " dst: " << i << "\n";

    for (int i = 0; i < V; i++)
        cout << "cost of " << i << " from source: " << distance[i] << "\n";

    return false;
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<edge> Edges;

    for (int i = 0; i < E; i++)
    {
        edge e;
        cin >> e.src >> e.dst >> e.wt;
        Edges.push_back(e);
    }

    if (BellmanFord(V, Edges))
        cout << "\nThe given graph contains a negative edge weight cycle\n";

    return 0;
}

// O(E.V)