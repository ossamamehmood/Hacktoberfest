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
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int diff[n];
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            string s;
            cin>>s;
            int count = 0;
            for(int i=0;i<x;i++){
                if(s[i]=='U')
                    count++;
                else 
                    count--;
            }
            diff[i] = count;
            //cout<<arr[i]<<" "<<diff[i]<<endl;
 
        }
 
        for(int i=0;i<n;i++){
            cout<<((arr[i]-diff[i]+10)%10)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
