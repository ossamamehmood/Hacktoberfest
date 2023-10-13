#include<iostream>
using namespace std;
int n;
int graph[50][50], visited[50]; 
int queue[50],front = -1,rear = -1;
int count = 0;
int bfs (int);

int enqueue (int value){
    if (rear == 50){
        cout << "Queue is full." << endl;
    }
    else{
        rear ++ ; 
        queue[rear]=value; 
        if (front == -1)
            front ++; 
    }
}

int dequeue(){

    if (count > n-2)
        exit(0);
    if (front == -1)
        cout << "Queue is empty" << endl;
    else{
        cout << " -> " << queue[front];  
        count ++; 
        int cc = queue[front]; 
        front++;
        bfs (cc);
    }
}

int bfs (int val){   
    visited[0]=1;                              
    for (int j=0; j<n; j++){ 
        if (!visited[j] && graph[val][j]==1){   // checks visited and neighour vertices
            visited[j] = 1; 
            enqueue(j);
        }
    }
    dequeue();
}

int main()
{
    cout << "Enter no. of vertices in graph : ";
    cin >> n;
    cout << "Enter the adjency matrix of " << n << " vertices : " << endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }
    cout << "BFS graph traversal : ";
    cout << "0"; // starting vertex
    bfs(0);   // inserting starting vertex
    return 0;
}

/*
0 1 0 1 0 0 0
0 0 1 0 0 0 0
0 0 0 0 1 0 1 
0 0 0 0 0 1 0 
0 1 0 0 0 1 0
0 0 0 0 0 0 0 
0 0 0 0 1 0 0
*/