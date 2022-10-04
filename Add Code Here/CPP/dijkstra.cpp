// C++ program implementing dijkstra's algorithm. 
// Dijkstra's algorithm is used to find the shortest paths from single source to all vertices of a graph. 

#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;
const int INF = 1e9;
vector<int> vis(N);
vector<pair<int,int>> g[N]; // weithed graph, pair -> <node, weight>

// dijstra algorithm funciton
void dijkstra(int src, int nodes){
    vector<int> dist(N, INF);

    set<pair<int, int>> set; // pair -> <wt, node>
    set.insert({0, src}); // assign wt 0 to source vertex
    dist[src] = 0;

    // first insert <wt,source> pair to set
    // Two main functions  are : 
    // 1. update the wt of childs if possible 
    // 2. then select the new node based on min wt. ( thus used set data structure )

    while(set.size() > 0){
        auto node = *set.begin(); // gives the min weight node pair
        int vertex = node.second;
        int distance = node.first;
        set.erase(set.begin());
        if(vis[vertex]) continue;
        vis[vertex] = 1;

        for(auto child: g[vertex]){
            int child_v = child.first;
            int wt = child.second;
            if(dist[vertex] + wt < dist[child_v]){
                dist[child_v] = dist[vertex] + wt;
                set.insert({dist[child_v], child_v});
            }
        }
    }

    cout << "vertex    distance " << endl;
    for(int i=0; i<nodes; i++){
        cout << i << " \t\t  " << dist[i] << endl;
    }
}

int main(){
    int nodes, edges;
    cout << "Enter number of nodes and edges : ";
    cin >> nodes >> edges;
     cout << "Enter "<< edges << " pairs of src, dest, wt vertices of a edge : ";

    for(int i=0; i< edges; i++){
        
        int x,y,wt; // wt is the weight of the edge connecting x, y
        cin >> x >> y >> wt;
        g[x].push_back({y,wt}); 
    }

    dijkstra(0, nodes); // assuming 0 as single source here

    return 0;
}
