#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>>graph[1000];
int visited[1000];


void dfs(int src){
    stack<pair<int,string>>s;
    s.push(make_pair(src,to_string(src)+""));

    while(s.size()>0){
      auto current = s.top();
      s.pop();

      if(visited[current.first]==1){
          continue;
      }
      visited[current.first]=1;
        cout<<current.first<<"@"<<current.second<<endl;
      for(auto x: graph[current.first]){
          s.push(make_pair(x.first,current.second+to_string(x.first)));
      }

    }




}



int main(){
        
        int n,m;
        cin>>n>>m;
        for(int i=0;i<m;i++){
         int x,y,z;
         cin>>x>>y>>z;
         graph[x].push_back(make_pair(y,z));
         graph[y].push_back(make_pair(x,z));

        }
        int src;
        cin>>src;


dfs(src);





    return 0;
}
