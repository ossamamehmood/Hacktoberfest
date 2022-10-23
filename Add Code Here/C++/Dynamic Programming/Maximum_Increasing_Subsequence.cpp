#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum sum of an increasing subsequence
int MSIS(vector<int> const &nums, int i, int prev, int sum)
{
	// base case: nothing is remaining
	if (i == nums.size()) {
		return sum;
	}

	// case 1: exclude the current element and process the
	// remaining elements
	int excl = MSIS(nums, i + 1, prev, sum);

	// case 2: include the current element if it is greater
	// than the previous element
	int incl = sum;
	if (nums[i] > prev) {
		incl = MSIS(nums, i + 1, nums[i], sum + nums[i]);
	}

	// return the maximum of the above two choices
	return max(incl, excl);
}

int main()
{
	vector<int> nums = { 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11 };

	cout << "The maximum sum of increasing subsequence is " <<
			MSIS(nums, 0, INT_MIN, 0);

	return 0;
}
