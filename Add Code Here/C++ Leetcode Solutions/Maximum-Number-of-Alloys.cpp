// Question 3 from Leetcode Weekly Contest 363
// Question ID: 2861
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
      long long ans=0;
      for(int i=0; i<k ;i++){
      int low=0;
      int hi = 1e9;
      
      while(low<=hi){
        long long mid = low-(low-hi)/2;
        long long currcost=0;
        for(int j=0; j<n; j++){
          long long int x = mid*composition[i][j];
          if(stock[j]>=x) continue;
          else{
              long long y = (x-stock[j])*cost[j];
              currcost+= y;
          }
      }
      if(currcost<=budget){
        ans = max(ans,mid);
        low = mid+1;
      }
      else{
        hi = mid-1;
      }
        
    }
      }
      return ans;
    }
};