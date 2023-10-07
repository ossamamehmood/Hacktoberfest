// One the most important and valueable question in DSA
/* 
42. Trapping Rain Water

Level : Hard

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
 

Constraints:

n == height.length
1 <= n <= 2 * 104
0 <= height[i] <= 105

*/

// My Solution 

class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int leftmax[] = new int[n];
        leftmax[0] = height[0];
        for(int i =1; i< n; i++){
            leftmax[i] = Math.max(height[i], leftmax[i-1]);
        }
        int rightmax[] = new int[n];
        rightmax[n-1] = height[n-1];
        for(int i =n-2; i >=0; i--){
            rightmax[i] = Math.max(height[i], rightmax[i+1]);
        }
        int trappedwater=0;
        for(int i =0; i<n; i++){
            int waterlevel = Math.min(leftmax[i], rightmax[i]);
            trappedwater += (waterlevel - height[i]) * 1;
        }
        return trappedwater;
    }e
}