#include<bits/stdc++.h>
using namespace std;
int main(){
   int n=8;
   int arr[8] = {4,3,2,7,8,2,3,1};
   unordered_map<int,int> mp;
   for (int i = 0; i < n; i++)
   {
      mp[arr[i]]++;
   }
   vector<int> v;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        cout << itr->first << '\t' << itr->second << '\n';
        if(itr->second==2){
         v.push_back(itr->first);
        }
    }
    
    for(auto x:v){
      cout<<x<<endl;
    }
 


}
