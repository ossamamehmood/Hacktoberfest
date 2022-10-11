// https://leetcode.com/problems/find-k-closest-elements/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        
        vector<int> ans;
        
        
        for(int z:arr){
            pq.push({abs(z-x),z});
        }
        
        while(k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        sort(ans.begin(),ans.end());
        
        
        
        
    return ans;    
        
        
        
    }
};
