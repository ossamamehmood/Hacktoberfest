#include<bits/stdc++.h>
using namespace std;

int knapsack(int w[],int p[],int n,int W)
{
    int k[n+1][W+1];
    for(int i=0;i<n+1;i++){
        k[i][0]=0;
    }
    for(int i=1;i<W+1;i++){
        k[0][i]=0;
    }

    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(w[i-1]<=j)
                k[i][j]=max(k[i-1][j],k[i-1][j-w[i-1]]+p[i-1]);
            else
                k[i][j]=k[i-1][j];
        }
    }

    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            cout<<k[i][j]<<" ";
        }
        cout<<endl;
    }
    return k[n][W];
}

int main()
{
    int w[]={2,3,4,5};
    int p[]={1,2,5,6};
    int W = 8;
    cout<<"max profit is "<<knapsack(w,p,4,W)<<endl;
}