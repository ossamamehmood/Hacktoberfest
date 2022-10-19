// Link to Problem : https://www.codingninjas.com/codestudio/problems/shortest-safe-route-in-a-field-with-landmines_1164264?leftPanelTab=0

#include<bits/stdc++.h>

struct node{
    int x,y;
};

bool isSafe(vector<vector<int>> &field, vector<vector<int>> dist, int x, int y, int m, int n){
    return (x>=0 && x<m && y>=0 && y<n && field[x][y]==1 && dist[x][y]==-1);
}

bool isValid(vector<vector<int>> &field, int x, int y, int m, int n){
    return (x>=0 && x<m && y>=0 && y<n);
}

int shortestPath(vector<vector<int>> &field)
{
	int m = field.size();
    int n = field[0].size();
    int row[] = {1,0,0,-1};
    int col[] = {0, -1, 1, 0};
//     int rowNum[] = { -1, 0, 0, 1 };
// 	int colNum[] = { 0, -1, 1, 0 };
//     q.push({0,0})
    int x,y,xnew, ynew, d;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(field[i][j]==0){
                for(int k=0;k<4;k++){
                    xnew = i+row[k];
                    ynew = j+col[k];
                    if(isValid(field, xnew, ynew,m,n)){
                        field[xnew][ynew]=-1;
                    }
                }
            }
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(field[i][j]==-1)
                field[i][j]=0;
        }
    }
    
   int dist[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            dist[i][j]=-1;
    }
    
    queue<node> q;
    
    for(int i=0;i<m;i++){
        if(field[i][0]==1){
        	q.push({i,0});
            dist[i][0]=0;
        }
    }
    
    node temp;    
    while(q.empty()==false){
        temp = q.front();
        q.pop();
        x = temp.x;
        y = temp.y;
        d = dist[x][y];
        
        for(int k=0;k<4;k++){
            xnew = x+row[k];
            ynew = y+col[k];
//             cout << "lala :" << xnew << " : " <<ynew << endl;
//             cout << "isSafe :" << isSafe(field, dist, xnew, ynew) << endl;
            if(isSafe(field, dist, xnew, ynew,m,n)){
                dist[xnew][ynew] = d+1;
//                 cout << xnew << " : " <<ynew << " : " << dist[xnew][ynew] << endl;
                q.push({xnew, ynew});
            }
        }
    }
    int ans = INT_MAX;

    for(int i=0;i<m;i++){
        if(dist[i][n-1]!=-1 && field[i][n-1]==1)
        	ans = min(ans, dist[i][n-1]);
    }

    if(ans==INT_MAX)
        return -1;
    return ans;
	// Write your code here.
}
