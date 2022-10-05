#include <bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m, int n)
{
	
	int L[m + 1][n + 1]; //matrix initialiazation

//bottom up manner
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}


	return L[m][n];
}

// Driver program to test above function
int main()
{
	
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of LCS is: " << lcs(X, Y, m, n);

	return 0;
}
//this is the tabulated implementaion of longest common subsequence problem.
//time complexity is O(mn)