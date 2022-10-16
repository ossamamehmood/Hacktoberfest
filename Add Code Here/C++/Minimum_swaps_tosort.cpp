#include<bits/stdc++.h>
using namespace std;



class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    vector<pair<int,int>> arr(n);
	    for(int i=0;i<n;i++){
	        arr[i].first = nums[i];
	        arr[i].second = i;
	    }
	    sort(arr.begin(),arr.end());
	    int c = 0;
	    vector<bool> vis(n,false);
	    int ans = 0;
	    for(int i=0;i<n;i++){
	        if(vis[i] || arr[i].second == i)
	         continue;
	        c = 0;
	        int j = i;
	        while(!vis[j]){
	            vis[j] = true;
	            j = arr[j].second;
	            c++;
	        }
	        ans += (c>0)? c-1:0;
	    }
	    return ans;
;	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
} 
