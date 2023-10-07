class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0;
        int leftIdx = 0, rightIdx = height.size() - 1;
        
        while(leftIdx < rightIdx){
            maxArea = max(maxArea, min(height[leftIdx], height[rightIdx]) * (rightIdx - leftIdx));
            if(height[leftIdx] < height[rightIdx])
                leftIdx++;
            else
                rightIdx--;
        }
        
        return maxArea;
    }
};
