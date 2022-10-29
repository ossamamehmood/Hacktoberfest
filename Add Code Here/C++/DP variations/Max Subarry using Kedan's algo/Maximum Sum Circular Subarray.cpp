// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    // Max subrray in cicrcular array = cumulative sum - min subarry sum
    int maxSubarraySumCircular(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        int min_sofar = INT_MAX, max_sofar = INT_MIN;
        int mini = 0, maxi = 0;

        int sum = accumulate(nums.begin(), nums.end(), 0);

        for (auto &x : nums)
        {
            // Kadane's Algorithm to find Maximum subarray sum.
            // dp approach of kedans
            maxi = max(maxi + x, x);
            max_sofar = max(max_sofar, maxi);

            // dp approach of kedans
            // Kadane's Algorithm to find Minimum subarray sum.
            mini = min(mini + x, x);
            min_sofar = min(min_sofar, mini);
        }

        // if all are negative number then -> //! corner case
        // we return max_so far i.e smallest negative value

        return max_sofar > 0 ? max(max_sofar, sum - min_sofar) : max_sofar;
    }
};

int main()
{
    // Main function goes here
    return 0;
}