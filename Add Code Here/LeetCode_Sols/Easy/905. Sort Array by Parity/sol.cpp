#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> sortArrayByParity(vector<int>& nums) {
    
    int left = 0, right = 0;
    int n = nums.size();
        
    while (right < n) {
      if (nums[right] % 2 == 0) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;  
      }
      right++;
    }
    
    return nums;
  }
};

int main() {

  // call the fn here
  
  return 0;
}