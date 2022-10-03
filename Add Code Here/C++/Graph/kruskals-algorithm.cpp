#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int parent;
    int rank;
};

struct Edge
{
    int from;
    int to;
    int weight;
};

bool comparator(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int dsuf_find(int v, vector<Node> dsuf)
{
    if (dsuf[v].parent == -1)
        return v;
    return dsuf[v].parent = dsuf_find(dsuf[v].parent, dsuf);
}

void dsuf_union(int v1, int v2, vector<Node> &dsuf)
{
    int v1_p = dsuf_find(v1, dsuf);
    int v2_p = dsuf_find(v2, dsuf);

    if (dsuf[v1_p].rank < dsuf[v2_p].rank)
        dsuf[v1_p].parent = v2_p;
    else if (dsuf[v2_p].rank < dsuf[v1_p].rank)
        dsuf[v2_p].parent = v1_p;
    else
    {
        dsuf[v1_p].parent = v2_p;
        dsuf[v2_p].rank += 1;
    }
}

void Kruskals(vector<Edge> edges, vector<Node> &dsuf, vector<Edge> &mst)
{
    sort(edges.begin(), edges.end(), comparator);
    for (auto e : edges)
    {
        // find abs parents of edges
        int v1_p = dsuf_find(e.from, dsuf);
        int v2_p = dsuf_find(e.to, dsuf);

        if (v1_p == v2_p)
            continue;

        mst.push_back(e);
        dsuf_union(v1_p, v2_p, dsuf);
        if (mst.size() == dsuf.size() - 1)
            break;
    }
}

int main()
{
    int E, V;
    cin >> E >> V;

    vector<Edge> edge_list;

    // init
    vector<Node> dsuf(V);
    for (int i = 0; i < V; i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    // create edge list
    for (int i = 0; i < E; i++)
    {
        Edge e;
        cin >> e.from >> e.to >> e.weight;
        edge_list.push_back(e);
    }

    vector<Edge> mst;
    Kruskals(edge_list, dsuf, mst);

    cout << "MST Edges \n";
    int weight = 0;

    for (auto i : mst)
    {
        weight += i.weight;
        cout << i.from << " " << i.to << " " << i.weight << "\n";
    }

    cout << "mst weight: " << weight;

    return 0;
}