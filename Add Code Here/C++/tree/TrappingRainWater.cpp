/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

#include <iostream>
#include <vector>
using namespace std;
 
int trap(vector<int>& height) 
{
    int n = height.size();
   
    // indices to traverse the elevations.
    int left = 0;
    int right = n-1;
  
    // To store Left max and right max
    // for two pointers left and right
    int l_max = 0;
    int r_max = 0;
  
    // To store the total amount
    // of rain water trapped
    int result = 0;
    while (left <= right)
    {
  
      // We need check for minimum of left
      // and right max for each element
      if(r_max <= l_max)
      {
  
        // Add the difference between
        // current value and right max at index r
        result += max(0, r_max-height[right]);
  
        // Update right max
        r_max = max(r_max, height[right]);
  
        // Update right pointer
        right -= 1;
      }
      else
      {
  
        // Add the difference between
        // current value and left max at index l
        result += max(0, l_max-height[left]);
  
        // Update left max
        l_max = max(l_max, height[left]);
  
        // Update left pointer
        left += 1;
      }
    }
    return result;
}
 
// Driver code
int main() {
    int n;
    cout << "Enter the number of elevations: ";
    cin >> n;
    cout << "Enter elevations vector: ";
    vector<int> height(n);
    for(int i = 0;i<n;i++)
    {
        cin >> height[i];
    }
    cout << trap(height) << endl;
}

/*
    Test Case - 1: 

    Enter the number of elevations: 6
    Enter elevations vector: 4 2 0 3 2 5

    Answer: 9

    Test Case - 2: 

    Enter the number of elevations: 12
    Enter elevations vector: 0 1 0 2 1 0 1 3 2 1 2 1
    Answer: 6
*/