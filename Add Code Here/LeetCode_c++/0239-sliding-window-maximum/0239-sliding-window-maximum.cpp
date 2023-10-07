class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (k == 0) 
            return ans;
        deque<int> window_indices;  // Use a deque to store indices
        for (int i = 0, n = (int)nums.size(); i < n; i++) {
            // Remove indices that are out of the sliding window
            while (!window_indices.empty() && window_indices.front() <= i - k)
                window_indices.pop_front();
            
            // Remove indices of elements smaller than the current element
            while (!window_indices.empty() && nums[window_indices.back()] <= nums[i])
                window_indices.pop_back();
            
            window_indices.push_back(i);  // Add the current index to the window
            
            if (i >= k - 1)
                ans.push_back(nums[window_indices.front()]);  // Add the maximum element to the ans
        }
        return ans;
    }
};
