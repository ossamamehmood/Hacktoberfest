


#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& stalls,int k,int mid){
    int temp=-1e9;
    for(auto it:stalls){
        if(it-temp>=mid){
            k--;
            
        temp=it;
        }
        if(k==0) return true;
    }
    return false;

}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n=stalls.size();
    sort(stalls.begin(),stalls.end());
    int l=1,r=stalls[n-1]-stalls[0];
    while(l<=r){
        int mid=(l+r)/2;

        if(canPlace(stalls,k,mid)){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return r;
}

int main()
{
    vector<int> stalls = {0, 3, 4, 7, 10, 9};
    int k = 4;
    int ans = aggressiveCows(stalls, k);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    return 0;
}
