#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int parent;
    int rank;
};

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

bool isCyclic(vector<pair<int, int>> edges, vector<Node> &dsuf)
{
    for (auto e : edges)
    {
        // find abs parents of edges
        int v1_p = dsuf_find(e.first, dsuf);
        int v2_p = dsuf_find(e.second, dsuf);

        if (v1_p == v2_p)
            return true;

        // dsuf[v1_p] = v2_p;
        dsuf_union(v1_p, v2_p, dsuf);
    }
    return false;
}

int main()
{
    int E, V;
    cin >> E >> V;

    vector<pair<int, int>> edge_list;

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
        int from, to;
        cin >> from >> to;
        edge_list.push_back({from, to});
    }

    if (isCyclic(edge_list, dsuf))
        cout << "The given graph is cyclic";
    else
        cout << "The given graph is acyclic";

    cout << "\n";

    for (auto i : dsuf)
        cout << i.parent << " " << i.rank << "\n";

    return 0;
}