#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

    for(int row=0; row<mat.size(); row++) {
      int soldierCount = 0;
      
      for(int col=0; col<mat[row].size(); col++) {
        soldierCount += mat[row][col];
        
        if(mat[row][col] == 0) 
          break;
      }
      
      minHeap.push({soldierCount, row});
      
      if(minHeap.size() > k)
        minHeap.pop();
    }

    vector<int> result;

    while(!minHeap.empty()) {
      result.push_back(minHeap.top().second);
      minHeap.pop();
    }

    return result;
  }
};

int main() {
  //in this we see the sol through an example and call the fn here itself
  vector<vector<int>> mat {{1,1,0,0,0},
                           {1,1,1,1,0},
                           {1,0,0,0,0},
                           {1,1,0,0,0},
                           {1,1,1,1,1}};
                           
  int k = 3;
  
  Solution sol;
  vector<int> weakestRows = sol.kWeakestRows(mat, k);

  for(int row : weakestRows) 
    cout << row << " ";

  return 0;
}