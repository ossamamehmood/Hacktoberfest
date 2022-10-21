//https://leetcode.com/problems/largest-rectangle-in-histogram/
#include <algorithm>
class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n){
      stack<pair<int,int>> st;
      vector<int> right(n);
for(int i=n-1;i>=0;i--){
 if(st.size()==0){
  right.push_back(-1);
  }

 else if(st.size()>0 && st.top().first<arr[i]){
   right.push_back(st.top().second);
    }

 else if(st.size()>0 && st.top().first>=arr[i]){
   while(st.size()>0 && st.top().first>=arr[i]){
    st.pop();
     }

  if(st.size()==0){
    right.push_back(-1); 
   }
  else{
    right.push_back(st.top().second);
   }
}

 st.push({arr[i],i});
}
reverse(right.begin(),right.end());
return right;
            
        }
    
    

vector<int> prevSmallerElement(vector<int> arr , int n){
    stack<pair<int,int>> s;
 vector<int> left;
for(int i=0;i<n;i++){
 if(s.size()==0){
  left.push_back(-1);
  }

 else if(s.size()>0 && s.top().first<arr[i]){
   left.push_back(s.top().second);
    }

 else if(s.size()>0 && s.top().first>=arr[i]){
   while(s.size()>0 && s.top().first>=arr[i]){
    s.pop();
     }

  if(s.size()==0){
    left.push_back(-1); 
   }
  else{
    left.push_back(s.top().second);
   }
}

 s.push({arr[i],i});
}
return left;
}
public:
    int largestRectangleArea(vector<int>& heights) {
       int n = heights.size();
        vector<int> next(n);
        next = nextSmallerElement(heights,n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);
        
        int area = INT_MIN;
        
        for(int i=0;i<n;i++){
            int l = heights[i];
            
            if(next[i]==-1){
                next[i]=n;
            }
            
             int b = next[i]-prev[i]-1;
            
            int newArea = l*b;
            area = max(area,newArea);
            
        }
        return area;
    }
};
