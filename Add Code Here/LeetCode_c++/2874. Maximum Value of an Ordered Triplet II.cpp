//https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>p(n,0),s(n,0);
        int m=nums[0];
        for(int i=1;i<n;i++){
            p[i]=m;
            m=max(m,nums[i]);
        }
        m=nums[n-1];
        for(int i=n-2;i>=0;i--){
            s[i]=m;
            m=max(m,nums[i]);
        }
        long long a=0;
        for(int i=0;i<n-1;i++){
            long long v= (p[i]-(1LL*nums[i]))*(1LL*s[i]);
            a=max(a,v);
        }
        return a;
    }
};
        
       