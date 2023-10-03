class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n1,j,k;        
        for(int i=0;i<n-2;i++) {
            if(i==0 || (i>0 && nums[i]!=nums[i-1])) {
                n1=-nums[i];
                j=i+1;k=n-1;
                while(j<k) {
                    int s=nums[j]+nums[k];
                    if(s==n1) {                                        
                        ans.push_back({-n1,nums[j],nums[k]});
                        while(j+1<k && nums[j]==nums[j+1]) j++;
                        while(k-1>j && nums[k]==nums[k-1]) k--;
                        j++;k--;
                    }
                    else if(s<n1) {
                        j++;
                    }
                    else {
                        k--;
                    }
                }
            }
        }
        return ans;        
    }
};