class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0,h=n-1,ans=INT_MAX,lmin=INT_MAX;
        for(int i=0;i<n;i++) {
            int a=nums[i];
            int k=t-a;
            l=i+1,h=n-1;
            while(l<h) {
                int bc=nums[l]+nums[h];
                if(bc<k) {
                    l++;  
                } else if(bc>k) {
                    h--;
                } else if(bc==k) {
                    return bc+a;
                }
                if(lmin>abs(t-bc-a)) {
                    lmin=abs(t-bc-a);
                    ans=bc+a;
                }
            }
            
        }
        return ans;
    }
};