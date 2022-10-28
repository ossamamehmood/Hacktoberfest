const int MOD = 1000000007;

void maximalANDSubsequencesHelper(vector<int> &arr, int k, int index, int current, int &maxVal, int &count)
{
	if (k == 0)
	{
		// Generated a valid k-element subsequence.
		if (current > maxVal)
		{
			// Found a larger AND value. So, update the maximum value.
			maxVal = current;

			// Reset the counter to 1.
			count = 1;
		}
		else if (current == maxVal)
		{
			// Same maximum value is encountered. So, increment the counter.
			count = ((long long)count + 1) % MOD;
		}
		return;
	}

	if (index == arr.size())
	{
		// No more elements in the array, so return.
		return;
	}

	// Generate the remaining subsequence.
	// Ignore the current element.
	maximalANDSubsequencesHelper(arr, k, index + 1, current, maxVal, count);

	// Include the current element in the subsequence.
	maximalANDSubsequencesHelper(arr, k - 1, index + 1, current & arr[index], maxVal, count);
}

vector<int> maximalANDSubsequences(vector<int> &arr, int k)
{
	int maxVal = -1;
	int count = 0;

	// Call the rescursive function for every index in the array.
	for (int i = 0; i < arr.size(); i++)
	{
		int current = arr[i];
		maximalANDSubsequencesHelper(arr, k - 1, i + 1, current, maxVal, count);
	}

	vector<int> ans = {maxVal, count};

	return ans;
}