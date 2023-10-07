// lc 35

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // Write your code here.
        int lo = 0;
        int hi = nums.size() - 1;
        int ans = nums.size();
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;

            if (nums[mid] >= target)
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}