#include "bits/stdc++.h"
#define vi vector<int>
#define endl '\n'
#define int long long
#define ll long long
#define pb push_back
const int N = 1e5+10;
const int INF = 1e18+10;
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
signed main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    fast();
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        map<int,vector<int>>mp;
         for(int i=0;i<n;i++){
            int x;
            cin>>x;
            mp[x].pb(i);
            
         }
        for(int i=0;i<k;i++){
             int a,b;
             cin>>a>>b;
             //cout<<mp[a].size()<<mp[b].size()<<endl;
            int x=0,y=0;
             bool answer = true;
             if(mp[a].size()==0||mp[b].size()==0){
                answer = false;
             }
           else{
x = mp[a][0];
y = mp[b][mp[b].size()-1];
 
           }
           
 
            if(answer){
                if(y-x>0){
 
                    cout<<"YES"<<endl;
                }
                else
                    cout<<"NO"<<endl;
            }
            else
                cout<<"NO"<<endl;
        
            }
    }    
    return 0;
}
