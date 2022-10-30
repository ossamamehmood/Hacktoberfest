
#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
bool flag;
vector<int>save;

bool bestsum(int n,int m,int a[]){
    int minlen[n+1];
    int par[n+1];
    memset(minlen,0,sizeof(minlen));
    memset(par,0,sizeof(par));
    for(int i=1;i<=n;i++){
        int l=-1; // if -1 then no solution
        int p=0;
        for(int j=0;j<m;j++){
            int r=i-a[j];
            if(r>=0&&minlen[r]>=0){ // check r has solution or not
                if(l==-1||minlen[r]<l){ // check is optimal or not
                    l=minlen[r]+1;
                    p=r;
                }
            }
        }
        minlen[i]=l;
        par[i]=p;
    }
    if(minlen[n]>=0){
        int r=par[n];
        while(n>0){
            r=par[n];
            save.push_back(n-r);
            n=r;
        }
        flag = true;
    }
    else flag = false;
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
    }
    bestsum(n,m,a);
   for(int i=0;i<save.size();i++)cout<<save[i]<<endl;
    return 0;
}

