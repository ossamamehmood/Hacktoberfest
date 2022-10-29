// Shibam Debnath
// June ,2022

#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    // Kadane’s Algorithm:

    // in each step we hvae two choices ->
    // (i) Either we take the current element and continue the subarray sum
    // (ii) or we don't take the curr element and restart the subarry sum and store the prev sum in max_so_far
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();

        int max_so_far = INT_MIN;
        int max_end = 0;

        for (auto &x : nums)
        {
            max_end += x;

            // if at any stage sum is greater than max sum then update
            if (max_end > max_so_far)
            {
                max_so_far = max(max_so_far, max_end);
            }

            // if curr sum is < 0 then make it 0
            if (max_end < 0)
            {
                max_end = 0;
            }
        }

        return max_so_far;
    }
};

// DP appoach

// int max_so_far = a[0];
// int curr_max = a[0];

// for (int i = 1; i < size; i++)
// {
//     curr_max = max(a[i], curr_max + a[i]);
//     max_so_far = max(max_so_far, curr_max);
// }
// return max_so_far;

int main()
{
    // Main function goes here
    return 0;
}