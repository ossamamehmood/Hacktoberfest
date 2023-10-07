#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isMonotonic(vector<int>& nums) {
    
    if (nums[0] < nums[nums.size()-1]) {
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] < nums[i-1]) {
          return false;
        }
      }
    } else {
      for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i-1]) {
          return false; 
        }
      }
    }
    
    return true;
  }
};

int main() {
    
    //call your fn here

  return 0;
}