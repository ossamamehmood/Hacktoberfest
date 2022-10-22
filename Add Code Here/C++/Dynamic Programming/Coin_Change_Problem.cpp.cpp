#include <iostream>
#include <vector>
using namespace std;

// Function to find the total number of ways to get a change of `target`
// from an unlimited supply of coins in set `S`
int count(vector<int> const &S, int target)
{
	// if the total is 0, return 1
	if (target == 0) {
		return 1;
	}

	// return 0 if total becomes negative
	if (target < 0) {
		return 0;
	}

	// initialize the total number of ways to 0
	int result = 0;

	// do for each coin
	for (int c: S)
	{
		// recur to see if total can be reached by including current coin `c`
		result += count(S, target - c);
	}

	// return the total number of ways
	return result;
}

// Coin Change Problem
int main()
{
	// `n` coins of given denominations
	vector<int> S = { 1, 2, 3 };

	// total change required
	int target = 4;

	cout << "The total number of ways to get the desired change is "
		 << count(S, target);

	return 0;
}