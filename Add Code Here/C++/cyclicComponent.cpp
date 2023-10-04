#include <bits/stdc++.h>
using namespace std;

#define fr(i,n) for(int i=0;i<n;i++)
#define Fr(i,k,n) for(int i=k;i<n;i++)
#define frr(i,n) for(int i=n;i>=0;i--)

void createAdjList(vector<int> nodes[],int u,int v){
    nodes[u].push_back(v);
    nodes[v].push_back(u);
}

void AdjList(vector<int> nodes[] ,int n,int m){
    fr(i,m){
        int u,v;
        cin>> u >> v;
        createAdjList(nodes,u,v);
    }
}
void printAdj(vector<int> nodes[] ,int n){
    fr(i,n+1){
        cout<<i<<"->> ";
        for(auto it:nodes[i]){
            cout<<it<<",";
        }
        cout<<'\n';
    }
}

bool cyclecheck(vector<int> adj[],int node,bool visited[],int previous){
    visited[node]=1;

    for(auto it: adj[node]){
        if(visited[it] && it!=previous) return 1;
        if(!visited[it]){
            if(cyclecheck(adj,it,visited,node)){
                
                return 1;
            }
        }
    }
    return 0;
}

void solve(){
      int n,m;
      cin>>n>>m;
      vector<int> adj[n+1];
      bool visited[n+1],flag=0;
      memset(visited,0,sizeof(visited));
      AdjList(adj,n,m);
      printAdj(adj,n);
      cout<<'\n';

     
      Fr(i,1,n+1){
        if(!visited[i]){
            if(cyclecheck(adj,i,visited,-1)) {
                
                flag=1;
                break ;
            }
        }
      }
      if(flag)
        cout<<"graph has a cycle\n";
      else
        cout<<"graph has no cycle in it\n";  
   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t=1;
    //cin>>t;
    for(int i=0;i<t;i++){
        solve();
    }
    return 0;
} 
