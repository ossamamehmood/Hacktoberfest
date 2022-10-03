#include <iostream>
#include <vector>
using namespace std;

int dsuf_find(int v, vector<int> dsuf)
{
    if (dsuf[v] == -1)
        return v;
    return dsuf_find(dsuf[v], dsuf);
}

void dsuf_union(int v1, int v2, vector<int> &dsuf)
{
    int v1_p = dsuf_find(v1, dsuf);
    int v2_p = dsuf_find(v2, dsuf);

    // merge parents
    dsuf[v1_p] = v2_p;
}

bool isCyclic(vector<pair<int, int>> edges, vector<int> &dsuf)
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
    vector<int> dsuf(V, -1);

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

    for (int i : dsuf)
        cout << i << " ";

    return 0;
}