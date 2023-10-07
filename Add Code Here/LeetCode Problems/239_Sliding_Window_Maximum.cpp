class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> dq;

        vector<int> ans;
        int n = nums.size();

        for (int i=0; i<n; i++) {
            //out of bound remove
            //i-k == is that element which needs to be removed to move to another window size k 
            if (!dq.empty() && dq.front() == i-k) dq.pop_front();

            //keep iterating until deque is not empty and check from the back whatever is smaller or equal to and remove them 

            //it will remove every elemet smaller or equal than that element.

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            
            // now start taking answer in your array 

            if (i>=k-1) {
                ans.push_back(nums[dq.front()]);
            }

        }
        
        return ans;
    }
};
