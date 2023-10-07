//Niraj Patel
 
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       long long int n;
        cin>>n;
        long long int max=0;
       multiset<long long int> m;
       m.insert(0);
     long long int ans=0;
       for(int i=0;i<n;i++){
           long long int x;
           cin>>x;
           if(x==0){
               auto it=(--m.end());
               ans=ans+(*it);
               m.erase(it);
               m.insert(0);
           }
           else
           m.insert(x);
       }
       cout<<ans<<endl;
    }
}
