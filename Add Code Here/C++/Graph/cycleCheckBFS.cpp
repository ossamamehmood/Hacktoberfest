#include<bits/stdc++.h>
using namespace std;

void addEdge(int u,int v,vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


bool checkCyclebfs(int node, vector<int> adj[],vector<bool> &vis,vector<int> &parent)
{
    queue<int> q;
    q.push(node); 

    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(auto it: adj[front])
        {
            if(vis[it])
            {
                if(parent[it]!=front && it!=parent[front]){
                    return true;
                }
            }
            else if(!vis[it])
            {
                vis[it]=true;
                parent[it]=front;
                q.push(it);
            }
        } 
    } 
    return false;
}




int main() {
    //Graph Creation
    int E,V;
    cout<<"Enter the number of vertices and edges: ";
    cin>>V>>E;
    vector<int> adj[V];
    cout<<"Enter the edges:\n";
    for(int i=1;i<=E;i++)
    {
        int u,v;
        cin>>u>>v;
        addEdge(u,v,adj);
    } 
    //Cycle detection using BFS
    vector<bool> vis(V,false);
    vector<int> parent(V,-1);
    cout<<"\nCycle detection using BFS: \n";
    for(int i=0;i<V;i++){
        if(!vis[i])
        {
            vis[i] = true;
            if(checkCyclebfs(i,adj,vis,parent))
            {
                cout<<"\nCycle is present in graph\n";
                return 0;
            }
        }
    }
    cout<<"\nCycle is not present in graph\n";
    


return 0;
}

/*Example test case:
6 5
0 1
0 2
1 4
2 4
3 5 
*/