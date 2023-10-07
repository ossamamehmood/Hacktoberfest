#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {

        int n = nums.size();
        if (n == 0 || k <= 0)
            return {};

        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {

            if (!dq.empty() && dq.front() == i - k)
            {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1)
            {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};

int main()
{

    // call the fn here

    return 0;
}