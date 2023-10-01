#include<bits/stdc++.h>
using namespace std;

bool detect(int src,int parent,vector<int> adj[], vector<int> &vis){
        vis[src] = 1;
        
        for(auto &child: adj[src]){
            if(!vis[child]){
                if(detect(child,src,adj,vis) == true) return true;
            } 
            else if(child != parent) return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;++i){
            if(!vis[i]){
                if(detect(i,-1,adj,vis)== true) return true;
            }
        }
        return false;
    }
};
int main(){
int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
