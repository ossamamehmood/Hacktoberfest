#include<bits/stdc++.h>
using namespace std;
// C++ code to implement DFS 

class Graph{

    int v;
    vector<vector<int>> adj;
    vector<bool> visited;
public:
    Graph(int n){
        this->v = n;
        adj.resize(v);
        visited.resize(v);
    }

    void AddEdge(int a, int b, bool undir){
        adj[a].push_back(b);
        if (undir)
        {
            adj[b].push_back(a);
        }
    }

    void PrintGraph(){
        for (int i = 0; i < adj.size(); i++)
        {
            cout<<i<<"-->";
            for(auto j: adj[i]){
                cout<<j<<" ,";
            }
            cout<<endl;
        }   
    }

    bool allVisited(vector<bool> a){
        int sz = a.size();

        for(auto i: a){
            if (i == false)
            {
                return false;
            }
            
        }

        return true;
    }

    void dfs(int source){  // recursive traversal

        if (allVisited(visited) == true)
        {
            return;
        }
        
        cout<<source<<" ";
        visited[source] = true;
        for (int i = 0; i < adj[source].size(); i++)
        {
            if (visited[adj[source][i]] == false)
            {
                dfs(adj[source][i]);
            }
        }
        return;
    }
    
};

int main(){
    
    Graph g(7);
    g.AddEdge(1 ,0 ,1);
    g.AddEdge(1 ,2 ,1);
    g.AddEdge(0 ,4 ,1);
    g.AddEdge(2 ,3 ,1);
    g.AddEdge(3 ,4 ,1);
    g.AddEdge(3 ,5 ,1);
    g.AddEdge(4 ,5 ,1);
    g.AddEdge(5 ,6 ,1);

    g.dfs(1);
    
    return 0;
}
