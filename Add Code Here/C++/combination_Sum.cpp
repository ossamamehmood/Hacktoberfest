#include <algorithm>


void solve(vector<vector<int>> &result, int currIndex, int currSum, 
			vector<int> &currList, int B, vector<int> &ARR)
{
	if (currSum == B)
	{
		result.push_back(currList);
		return ;
	}
	if (currIndex == ARR.size())
	{
		return ;
	}

	solve(result, currIndex + 1, currSum, currList, B, ARR);


	int count = 0;

	while (currSum <= B)
	{
		count++;

		currSum += ARR[currIndex];

		currList.push_back(ARR[currIndex]);

		solve(result, currIndex + 1, currSum, currList, B, ARR);
	}

	/* We remove ARR[currIndex] from currList, 'count'
	   number of times for backtracking */
	while (count--)
	{
		currList.pop_back();
	}
}


vector<vector<int>> combSum(vector<int> &ARR, int B)
{
	sort(ARR.begin(), ARR.end());
	
	vector<vector<int>> result;

	vector<int> currList;

	solve(result, 0, 0, currList, B, ARR);

	return result;
}