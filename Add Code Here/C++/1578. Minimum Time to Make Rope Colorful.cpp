// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

class Solution {
public:
    int minCost(string c, vector<int>& t) {
        
        int ans=0;
        
        for(int i=0;i<c.length();){
            
            priority_queue<int,vector<int>,greater<int>> pq;
            
            int j=i;
            
            while(j<c.length() && c[j]==c[i]){
                pq.push(t[j]); j++;
                
            }
            
            while(pq.size()!=1)
            {
                ans+= pq.top();
            
                pq.pop();
            }
            
            i=j;
            
        }
        
        
     
        return ans;
        
        
        
        
    }
};
