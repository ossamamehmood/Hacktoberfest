#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {

        int target = 0;
        for (int num : nums)
        {
            target += num;
        }
        target -= x;

        if (target < 0)
        {
            return -1;
        }

        int left = 0;
        int curSum = 0;
        int maxLength = INT_MIN;

        for (int right = 0; right < nums.size(); right++)
        {
            curSum += nums[right];

            while (curSum > target)
            {
                curSum -= nums[left++];
            }

            if (curSum == target)
            {
                maxLength = max(maxLength, right - left + 1);
            }
        }

        return maxLength == INT_MIN ? -1 : nums.size() - maxLength;
    }
};

int main()
{

    // call the fn here

    return 0;
}