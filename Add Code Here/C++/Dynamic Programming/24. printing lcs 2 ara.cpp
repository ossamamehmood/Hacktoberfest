#include<bits/stdc++.h>
#define        ll        long long int
#define        ls        unsigned long long
#define         eps       1e-9
#define         M_E      2.718281828
#define         M_PI     3.1416
#define        MAX       500
#define        frin          for(ll i=0;i<n;i++)
#define        frjn          for(ll j=0;j<n;j++)
const int   mod=1e9+7;
using namespace std;
vector<ll>aa,bb;
int ara[101][101];

int editing_distance(vector<ll>&a,vector<ll>&b,int row,int col)
{
    for(int i=0;i<=row;i++)ara[i][0]=i;
    for(int i=0;i<=col;i++)ara[0][i]=i;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(a[i-1]==b[j-1]){
                ara[i][j]=min(ara[i][j-1]+1,min(ara[i-1][j]+1,ara[i-1][j-1]));
                //ara[i][j]=ara[i-1][j-1]+1;
            }
            else{
                 ara[i][j]=min(ara[i][j-1]+1,min(ara[i-1][j]+1,ara[i-1][j-1]+1));
                 //ara[i][j]=max(ara[i-1][j],ara[i][j-1]);
            }
        }
    }
    return ara[row][col];
}

/* using backtracking to find the allignment*/
void allignment(vector<ll>&a,vector<ll>&b,int i,int j)
{
    if(i==0 and j==0)return;
    if(i>0 and ara[i][j]==(ara[i-1][j]+1))
    {
       allignment(a,b,i-1,j);
       aa.push_back(a[i-1]);
       bb.push_back(-1);
    }
    else if(j>0 and ara[i][j]==(ara[i][j-1]+1))
    {
         allignment(a,b,i,j-1);
          aa.push_back(-1);
       bb.push_back(b[j-1]);
    }
    else
    {
         allignment(a,b,i-1,j-1);
          aa.push_back(a[i-1]);
       bb.push_back(b[j-1]);
    }
}
int main()
{
    int n,m,o;
    cin>>n;
     vector<ll>a(n);
     for(int i=0;i<n;i++)cin>>a[i];
     cin>>m;
     vector<ll>b(m);
     for(int i=0;i<m;i++)cin>>b[i];

    cout<<editing_distance(a,b,n,m)<<endl;
    allignment(a,b,n,m);

    vector<ll>d;
    for(int i=0;i<aa.size();i++){
        if(aa[i]==bb[i])d.push_back(aa[i]);
    }
    for(int i=0;i<d.size();i++)cout<<d[i]<<" ";
    cout<<endl;
    return 0;
}

