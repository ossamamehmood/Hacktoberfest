#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int trap(vector<int>& height) {
        int n=height.size();
        vector<int>left(n),right(n);
        left[0]=height[0];
        for(int i=1;i<n;i++){
            left[i] = max(left[i-1], height[i]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            right[i]=max(right[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
int main(){
    vector<int>height;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        height.push_back(a);
    }
    cout<<trap(height);
    return 0;
}
