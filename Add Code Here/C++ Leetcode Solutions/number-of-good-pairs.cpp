// https://leetcode.com/problems/number-of-good-pairs/
// 1512. Number of Good Pairs

// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j.

// Constraints:

// 1 <= nums.length <= 100
// 1 <= nums[i] <= 100

// Solution
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> count;
        int good_pairs=0;
        for(int num: nums){
            good_pairs+=count[num];
            count[num]++;
        }

    return good_pairs;
    }
};
