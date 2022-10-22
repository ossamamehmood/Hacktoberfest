#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

// Returns true if there exists a subset of `nums[]` with the given sum
bool subsetSum(vector<int> const &nums, int n, int sum)
{
	// return true if the sum becomes 0 (subset found)
	if (sum == 0) {
		return true;
	}

	// base case: no items left or sum becomes negative
	if (n < 0 || sum < 0) {
		return false;
	}

	// Case 1. Include the current item `nums[n]` in the subset and recur
	// for remaining items `n-1` with the remaining total `sum-nums[n]`
	bool include = subsetSum(nums, n - 1, sum - nums[n]);

	// return true if we get subset by including the current item
	if (include) {
		return true;
	}

	// Case 2. Exclude the current item `nums[n]` from the subset and recur for
	// remaining items `n-1`
	bool exclude = subsetSum(nums, n - 1, sum);

	// return true if we get subset by excluding the current item;
	// false otherwise
	return exclude;
}

// Returns true if given array `nums[0…n-1]` can be divided into two
// subsets with equal sum
bool partition(vector<int> const &nums)
{
	int sum = accumulate(nums.begin(), nums.end(), 0);

	// return true if the sum is even and the array can be divided into
	// two subsets with equal sum
	return !(sum & 1) && subsetSum(nums, nums.size() - 1, sum/2);
}

int main()
{
	// Input: a set of items
	vector<int> nums = { 7, 3, 1, 5, 4, 8 };

	if (partition(nums)) {
		cout << "Set can be partitioned";
	}
	else {
		cout << "Set cannot be partitioned";
	}

	return 0;
}