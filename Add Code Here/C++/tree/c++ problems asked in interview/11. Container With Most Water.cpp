Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of the line i is at (i, ai) and (i, 0). 
Find two lines, which, together with the x-axis forms a container, such that the container contains the most water.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
Example 2:

Input: height = [1,1]
Output: 1
Example 3:

Input: height = [4,3,2,1,4]
Output: 16
Example 4:

Input: height = [1,2,1]
Output: 2

Solution : 

class Solution {
public:
    int maxArea(vector<int>& height) {
        int current_area = INT_MIN;
        int area = 0 ;
        int left = 0, right = height.size()-1;
        while(left<right)
        {
            current_area = min(height[left],height[right])*(right-left);
            if(height[left]<height[right]) left++;
                else
                    right--;
            area = max(area, current_area);
        }
        return area;
    }
};
