#include<bits/stdc++.h>
using namespace std;

vector<int> g[10000];
bool vis[10000];

void dfs(int parent){

  vis[parent] = 1;

  for(auto child:g[parent]){
      if(vis[child] == 0)
        dfs(child);
  }

}
int main(){
    int nodes,edges;
    cin >> nodes >> edges;

    for(int i = 0 ; i < edges; i++){
       int a,b;
       cin >> a >> b;

        g[a].push_back(b);
        g[b].push_back(a);
    }  

    for(int i = 1; i <= nodes; i++){
      if(vis[i] == 0)
        dfs(i);
    }

    return 0;
}
