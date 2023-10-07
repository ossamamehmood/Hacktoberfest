// Question 3 from Leetcode Weekly Contest 364
// Question ID: 2866

class Solution {
public:
    void solve(vector<int>& nums, vector<long long>& pref){
        stack<pair<long long,long long>> st;
        int n = nums.size();
        pref[0] = nums[0];
        st.push({nums[0],0});
        for(int i=1; i<n; i++){
            while(nums[i]<st.top().first){
                st.pop();
                if(st.empty()) break;
            }
            if(st.empty()){
                pref[i] = nums[i];
                int x = i+1;
                pref[i]*=x;
            }
            else{
                pref[i] = nums[i]*(i-st.top().second)+pref[st.top().second];

            }
            st.push({nums[i],i});
            
        }
    }
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int n = maxHeights.size();
        vector<long long> pref(n);
        vector<long long> suff(n);
        solve(maxHeights,pref);
        reverse(maxHeights.begin(), maxHeights.end());
        solve(maxHeights,suff);
        reverse(suff.begin(), suff.end());
        reverse(maxHeights.begin(), maxHeights.end());
        long long ans=0;
        for(int i=0; i<n; ++i){
            ans = max(ans,(pref[i]+suff[i])-maxHeights[i]);
        }
        return ans;     
        
    }
};