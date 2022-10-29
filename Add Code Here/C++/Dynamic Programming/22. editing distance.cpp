#include<bits/stdc++.h>
#define        ll     long long int
using namespace std;
vector<char>aa,bb;
int ara[101][101];
string a,b;

int editing_distance(string a,string b,int row,int col)
{
    for(int i=0;i<=row;i++)ara[i][0]=i;
    for(int i=0;i<=col;i++)ara[0][i]=i;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=col;j++){
            if(a[i-1]==b[j-1]){
                ara[i][j]=min(ara[i][j-1]+1,min(ara[i-1][j]+1,ara[i-1][j-1]));
            }
            else{
                 ara[i][j]=min(ara[i][j-1]+1,min(ara[i-1][j]+1,ara[i-1][j-1]+1));
            }
        }
    }
    return ara[row][col];
}

/* using backtracking to find the allignment*/
void allignment(int i,int j)
{
    if(i==0 and j==0)return;
    if(i>0 and ara[i][j]==(ara[i-1][j]+1))
    {
       allignment(i-1,j);
       aa.push_back(a[i-1]);
       bb.push_back('-');
    }
    else if(j>0 and ara[i][j]==(ara[i][j-1]+1))
    {
         allignment(i,j-1);
          aa.push_back('-');
       bb.push_back(b[j-1]);
    }
    else
    {
         allignment(i-1,j-1);
          aa.push_back(a[i-1]);
       bb.push_back(b[j-1]);
    }
}
int main()
{
    int row,col;
    cin>>a>>b;
     row=a.size();
     col=b.size();
    cout<<editing_distance(a,b,row,col)<<endl;
    allignment(row,col);
    for(int i=0;i<aa.size();i++){
        cout<<aa[i];
    }
    cout<<endl;
    for(int i=0;i<bb.size();i++){
        cout<<bb[i];
    }
    cout<<endl;
    return 0;
}

