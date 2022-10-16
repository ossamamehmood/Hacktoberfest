//To detect whether cycle is there in undirected graph using bfs traversal
#include <iostream>
#include <vector>
#include<queue>
using namespace std;

bool detectcycle(int node,vector<int> &visited,vector<int> graph[]){

    visited[node] = true;
    queue <pair<int,int>> q;
    q.push({node,-1});

    while(!q.empty()){
         int value = q.front().first;
         int parent = q.front().second;
         q.pop();

         for(auto it : graph[value]){
            if(!visited[it]){
                visited[it] = true;
                q.push({it,value});
            }
            else if(it != parent){
                return true;
            }
         }
    }

    // if no cycle is present in current component of graph then we will return true 
    return false;
}

int main(){
    int vertice,edge;
    cin>>vertice>>edge;
    
    vector<int> visited(vertice+1,0);
    vector<int> graph[vertice+1];

    int x,y;
    for(int i=0;i<edge;i++){
         cin>>x>>y;
         graph[x].push_back(y);
         graph[y].push_back(x);
    }
   
    bool cycle = false;

    for(int i=1;i<=vertice;i++){
        if(!visited[i]){
            if(detectcycle(i,visited,graph)){
             cycle = true;
             break;
            }
        }
    }   
     cout<<cycle<<endl;

    return 0;
}