vector<long> emptyCells(int n, int k, vector<vector<int>> &tasks)
{
	vector<vector<int>> matrix(n, vector<int>(n, -1));

	vector<long> ans(k);

	for (int i = 0 ; i < k ; i++)
	{
		int x = tasks[i][0];
		int y = tasks[i][1];

		for (int j = 0 ; j < n ; j++)
		{
			matrix[x][j] = 0;
			matrix[j][y] = 0;
		}

		long count = 0;
		for (int j = 0; j < n; j++)
		{
			for (int p = 0; p < n; p++)
			{
				if (matrix[j][p] == -1)
				{
					count++;
				}
			}
		}

		ans[i] = count;
	}
	return ans;
}