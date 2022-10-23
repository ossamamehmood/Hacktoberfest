#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(int startVertex , int V , vector <int> adj[])
{
    //first we will creat a visited array and initialize it to false using memset
    bool visited[V];
    memset(visited , false , sizeof visited);
    //then we creat a list of queues
    list <int> queue ;
    
    //push and mark the visited index of the first element
    visited[startVertex] = true;
    queue.push_back(startVertex);
    
    //now we will traverse till the queue is not empty
    while(!queue.empty())
    {
        //pop the first element
        int curr = queue.front();
        cout<<"visited"<< curr<<endl;
        queue.pop_front();
    
    //now all the edges that are connected to the popped one are push onto the queue if they are not visited already
        for(auto i : adj[curr])
        {
            if(!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    
    bfs(2,5 , adj);
    
}
    
