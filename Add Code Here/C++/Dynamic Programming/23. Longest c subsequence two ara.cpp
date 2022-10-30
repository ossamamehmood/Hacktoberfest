#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
ll ara[101][101];
ll editing_distance(vector<ll>&a,vector<ll>&b,int row,int col)
{
    for(int i=0;i<=row;i++)ara[i][0]=0;
    for(int i=0;i<=col;i++)ara[0][i]=0;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(a[i-1]==b[j-1]){
                ara[i][j]=ara[i-1][j-1]+1;
            }
            else{
                 ara[i][j]=max(ara[i][j-1],ara[i-1][j]);
            }
        }
    }
    return ara[row][col];
}

int main()
{
    int row,col;
    cin>>row;
    vector<ll>a(row);
     for(int i=0;i<row;i++)cin>>a[i];
     cin>>col;
     vector<ll>b(col);
     for(int i=0;i<col;i++)cin>>b[i];
    cout<<editing_distance(a,b,row,col)<<endl;
    return 0;
}

