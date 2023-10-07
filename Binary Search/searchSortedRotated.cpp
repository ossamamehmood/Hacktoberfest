#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = -1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                return ans;
            }
            else if (nums[mid] >= nums[lo])
            { // left part sorted
                if (nums[mid] >= target and target >= nums[lo])
                {
                    hi = mid - 1;
                }
                else
                {
                    lo = mid + 1;
                }
            }
            else if (nums[mid] <= nums[lo])
            { // right half sorted
                if (nums[mid] <= target and target <= nums[hi])
                {
                    lo = mid + 1;
                }
                else
                {
                    hi = mid - 1;
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}