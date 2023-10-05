#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long minimumReplacement(vector<int> &nums)
    {

        long long ops = 0;
        long long prev = nums.back();

        for (int i = nums.size() - 2; i >= 0; i--)
        {

            long long num = nums[i];
            long long times = (num + prev - 1) / prev;
            ops += times - 1;

            prev = num / times;
        }

        return ops;
    }
};

int main()
{
    // call the fn here

    return 0;
}