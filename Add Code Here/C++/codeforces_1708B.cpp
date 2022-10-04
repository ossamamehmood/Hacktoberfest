#include "bits/stdc++.h"
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
    int t;
    cin>>t;
    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        vector<int>ans;
        bool isTrue = true;
        for(int i=1;i<=n;i++){
            if(r - r%i >= l){
                ans.pb(r - r%i);
            }
            else{
                isTrue = false;
                break;
            }
        }
        if(isTrue){
            cout<<"YES"<<endl;
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
