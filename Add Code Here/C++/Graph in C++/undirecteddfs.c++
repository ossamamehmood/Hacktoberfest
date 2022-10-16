#include<iostream>
#include<vector>
using namespace std;

bool dfsdetect(int node,int parent,vector<int> &visited,vector<int> graph[]){
    visited[node] = true;
    for(auto it : graph[node]){

        if(!visited[it]){
            if(dfsdetect(it,node,visited,graph)){
                return true;
            }
        }

        else if(it != parent){
            return true;
        }
    }

    return false;
}

int main(){
//input the number of vertices also take connection between these nodes and also create a visited array of and initialize all its value as 0 in java by default initialization will take place
 int vertice;
 cin>>vertice;

 vector<int> visited(vertice+1,0);
 vector<int> graph[vertice+1]; 

 int edge;
 cin>>edge;

 for(int i=0;i<edge;i++){
    int x,y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
 }

 bool batao = false;
 for(int i=1;i<=vertice;i++){
       if(!visited[i])
       {
          if(dfsdetect(i,-1,visited,graph)){
            batao = true;
            break;
          }
       }
 }
 
  cout<<batao<<endl;
    
    return 0;
}