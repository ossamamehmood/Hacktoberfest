#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n1,m,n2;
        cin>>n1>>m;
        vector<ll>v1(n1);
        vector<ll>c1(n1);
        for(ll i=0;i<n1;i++){
            cin>>v1[i];
            if(v1[i]<=m) c1.push_back(v1[i]);
            else if(v1[i]%m==0 && v1[i]>m)
            {
                    ll x=v1[i]/m;
                    while(x>0)
                    {
                        c1.push_back(m);
                        x-=1;
                    }
            }
            else if(v1[i]%m!=0 && v1[i]>m){
                    c1.push_back(v1[i]);
                }
            }
            cin>>n2;
            vector<ll>v2(n2);
            vector<ll>c2(n2);
            for(ll i=0;i<n1;i++){
            cin>>v2[i];
            if(v2[i]<=m) c2.push_back(v2[i]);
            else if(v2[i]%m==0 && v2[i]>m){
                    ll x=v2[i]/m;
                    while(x>0){
                        c2.push_back(m);
                        x-=1;
                    }
                }
            else if(v2[i]%m!=0 && v2[i]>m){
                    c2.push_back(v2[i]);
                }
            }
            (c1 == c2)?  cout << "YES\n" : cout << "NO\n";
        }
        return 0;
    }