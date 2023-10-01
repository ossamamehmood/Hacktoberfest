#include<bits/stdc++.h>
using namespace std;
vector<int> countGreater(vector<int>&arr, vector<int>&query) {



        vector<int> ans;


        // cout<<query[0]<<endl;

            for (int i = 0; i < query.size(); i++) {
                int curr=query[0];
                int greater=-1;

                for (int j = curr+1; i < arr.size(); i++)
                {   
                        greater=i+1;
                        break;
                }

                ans.push_back(greater);
            }

            return ans;


}
int main(){


    vector<int> arr={5,2,10,4};
    vector<int> q={0,1};
    vector<int> ans=countGreater(arr,q);
    for(auto x:ans){
        cout<<x<<endl;
    }


}