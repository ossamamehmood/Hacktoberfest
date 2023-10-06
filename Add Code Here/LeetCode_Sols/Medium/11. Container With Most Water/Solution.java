class Solution {
    public int maxArea(int[] height) {
        int maxArea = 0;
        int leftIdx = 0, rightIdx = height.length-1;
        
        while(leftIdx < rightIdx){
            maxArea = Math.max(maxArea, Math.min(height[leftIdx], height[rightIdx]) * (rightIdx - leftIdx));
            if(height[leftIdx] < height[rightIdx])
                leftIdx++;
            else
                rightIdx--;
        }
        
        return maxArea;
    }
}
