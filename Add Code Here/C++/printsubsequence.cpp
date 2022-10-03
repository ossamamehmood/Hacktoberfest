#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

  void print(vector<vector<int>> &ans,int index,vector<int> &ds,vector<int>& nums,int n){
        if(index==n){
            if(ds.size()==0){
                ans.push_back({});
            }
            else
        ans.push_back(ds);
            return;
        
        }
        ds.push_back(nums[index]);
        print(ans,index+1,ds,nums,n);
        ds.pop_back();
        
        print(ans,index+1,ds,nums,n);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int index=0;
        int n=nums.size();
        print(ans,index,ds,nums,n);
        
        
        return ans;
        
        
    }

int main(){

ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

ll n;
cin>>n;
vector<int> v(n);
for(ll i=0;i<n;i++){
    cin>>v[i];
}

vector<vector<int>> ans= subsets(v);

for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
        cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}

subsets(v);

    
    return 0;
}
