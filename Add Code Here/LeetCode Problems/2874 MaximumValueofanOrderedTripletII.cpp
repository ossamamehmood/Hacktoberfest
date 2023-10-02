class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxtillnow=0;
        long long bigdif=0;
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            long long a=bigdif*nums[i];
            if(a>ans)ans = a;
            long long b=maxtillnow-nums[i];
            if(b>bigdif)bigdif=b;
            long long c=nums[i];
            if(c>maxtillnow)maxtillnow=c;
        }
        return ans;
    }
};
