#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {

        int start = 0;
        int end = nums.size() - 1;
        int ans = start;

        while (nums[start] > nums[end])
        {
            int mid = (start + end) / 2;

            if (nums[mid] <= nums[start] && nums[mid] <= nums[end])
            {
                end = mid;
            }
            else if (nums[mid] >= nums[start] && nums[mid] >= nums[end])
            {
                start = mid + 1;
            }
            else
            {
                return nums[mid];
            }

            ans = start;
        }

        return nums[ans];
    }
};

int main()
{

    // call the fn here

    return 0;
}