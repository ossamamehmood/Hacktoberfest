#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {

        vector<int> result(2, -1);
        result[0] = findFirst(nums, target);
        result[1] = findLast(nums, target);

        return result;
    }

private:
    int findFirst(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }

            if (nums[mid] == target)
            {
                return mid;
            }
        }

        return -1;
    }

    int findLast(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (nums[mid] <= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }

            if (nums[mid] == target)
            {
                return mid;
            }
        }

        return -1;
    }
};

int main()
{

    // call the fn here

    return 0;
}