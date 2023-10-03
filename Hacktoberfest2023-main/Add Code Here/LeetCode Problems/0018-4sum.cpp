class Solution {
public:
    // 0  1 2 3 4 5
    //-2,-1,0,0,1,2 - n=6
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n0,n1,j,k;        
        for(int i=0;i<n-3;i++) {
            if(i==0 || (i>0 && nums[i]!=nums[i-1])) {                        
                n0=nums[i];
                for(int l=i+1;l<n-2;l++) {
                    if(l==i+1 || (l>i+1 && nums[l]!=nums[l-1]) ) {
                        n1=nums[l];                        
                        long long sum=(long long)t-n0-n1;
                        j=l+1;k=n-1;
                        while(j<k) {
                            int s=nums[j]+nums[k];
                            if(s==sum) {                                        
                                ans.push_back({n0,n1,nums[j],nums[k]});
                                while(j+1<k && nums[j]==nums[j+1]) j++;
                                while(k-1>j && nums[k]==nums[k-1]) k--;
                                j++;k--;
                            }
                            else if(s<sum) {
                                j++;
                            }
                            else {
                                k--;
                            }
                        }                        
                   }
                }
            }
        }
        return ans;        
    }
};