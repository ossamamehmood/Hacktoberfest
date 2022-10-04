#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    map<string,string>mp;
    for(int i=0; i<m; i++){
        string a,b;
        cin>>a>>b;
        if(a.length()>b.length())
        mp[a]=b;
        else
        mp[a]=a;

    }
    for(int i=0; i<n; i++){
        string x;
        cin>>x;
        cout<<mp[x]<<" ";
    }
    cout<<endl;

    
    return 0;
}
