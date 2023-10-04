#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9; 


struct Edge {
    int to, weight;
};


vector<vector<Edge>> prim(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<vector<Edge>> minSpanTree(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

   
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        if (u != start) {
           
            minSpanTree[u].push_back({start, weight});
            minSpanTree[start].push_back({u, weight});
        }

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int w = edge.weight;
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    return minSpanTree;
}

int main() {
    int n, m; 
    cin >> n >> m;

    
    vector<vector<Edge>> graph(n);

   
    for (int i = 0; i < m; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int startVertex; 
    cin >> startVertex;

    vector<vector<Edge>> minSpanTree = prim(graph, startVertex);

    
    for (int i = 0; i < n; ++i) {
        for (const Edge& edge : minSpanTree[i]) {
            cout << "Edge: " << i << " - " << edge.to << " Weight: " << edge.weight << endl;
        }
    }

    return 0;
}
