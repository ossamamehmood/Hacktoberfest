/*
A C++ program to find all the connected components in a graph.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> getConnectedComponents(int **edges, int n, int start, bool *visited)
{
    queue<int> vertices;
    vector<int> ans;
    vertices.push(start);
    visited[start] = true;
    // ans.push_back(start);

    while (!vertices.empty())
    {
        int current = vertices.front();
        ans.push_back(current);
        vertices.pop();
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[current][i] == 1 && i != current)
            {
                visited[i] = true;
                vertices.push(i);
                // ans.push_back(i);
            }
        }
    }
    return ans;
}

vector<vector<int>> getans(int **edges, int n)
{
    bool *visited = new bool[n];
    vector<vector<int>> components;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> ans = getConnectedComponents(edges, n, i, visited);
            components.push_back(ans);
        }
    }
    return components;
}

int main()
{

    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    vector<vector<int>> components = getans(edges, n);
    for (int i = 0; i < components.size(); i++)
    {
        sort(components[i].begin(), components[i].end()); // sorting individual vectors
        for (int j = 0; j < components[i].size(); j++)
        {
            cout << components[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
