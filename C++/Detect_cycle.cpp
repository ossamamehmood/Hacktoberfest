#include<iostream>
#include<vector>
#include<queue>
#define N 5
using namespace std ;
void AddEdge(vector<int> arr[N], int v, int u)
{
    arr[v].push_back(u);
    arr[u].push_back(v);
}
bool bfs(vector<int> arr[N],int s,int p,bool visited[N])
{
  
}
bool BFS(vector<int>arr[N],int s)
{
    bool visited[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    queue<int> q;
    q.push(s);
    visited[s] = true;
        s = -1;
    while (!q.empty())
    {
        int a = q.front();
        cout << a<< " ";
        q.pop();
        for (int x:arr[a])
        {
            if(visited[x]==false)
            {
                visited[x] == true;
                q.push(x);
            }
            else if(s!=x)
            {
                return true;
            }
        }
        s = a;
    }
    return false;
}
int main ()
{
    vector<int>arr[N];
    AddEdge(arr, 0, 1);
    AddEdge(arr, 1, 2);
    // AddEdge(arr, 2, 4);
    AddEdge(arr, 2, 3);
    AddEdge(arr, 3, 4);
    cout <<"\n"<< BFS(arr, 0);
}