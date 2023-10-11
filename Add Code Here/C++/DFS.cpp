#include<iostream>
using namespace std;
int graph[50][50], visited[50];
int stack[50],top = -1;
int n,count = 0;
int dfs (int);
int push (int value){
    if (top >= 50)
        cout << "Stack is full!!";
    else{
        top ++ ;
        stack[top]=value;
    }
} 
int pop(){
    if (top < -1)
        cout << "Stack is empty";
    else{
        if (count > n-2)
            exit(0);
        else{
            cout << " -> " << stack[top];
            count ++;
            int cc = stack[top];    // temporary storing top of stack vertex
            top--;
            dfs (cc);
        }
    }
}
int dfs (int val){
    visited[0]=1;
    for (int j=0; j<n; j++){
        if (!visited[j] && graph[val][j]==1){   // checks for visited and neighbour vertices
            visited[j]=1;
            push(j);
        }
    }
    pop(); 
}
int main()
{
    cout << "Enter the number of vertices in graph : ";
    cin >> n;
    cout << "Enter the values in form of matrix \n";
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> graph[i][j];
        }
    }
    cout << "DFS graph teversal : ";
    cout << "0";        // starting vertex
    dfs(0);     // insert starting vertex
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