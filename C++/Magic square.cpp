
#include <bits/stdc++.h>
using namespace std;


void MAgic(int n)
{
	int MAGICSq[n][n];

	
	memset(MAGICSq, 0, sizeof(MAGICSq));

	int i = n / 2;
	int j = n - 1;

	for (int num = 1; num <= n * n;) {
		if (i == -1 && j == n) 
		{
			j = n - 2;
			i = 0;
		}
		else {
			if (j == n)
				j = 0;

			if (i < 0)
				i = n - 1;
		}
		if (MAGICSq[i][j]) 
		{
			j -= 2;
			i++;
			continue;
		}
		else
			MAGICSq[i][j] = num++; 

		j++;
		i--; 
	}

	
	cout << "The Magic Square for n=" << n
		<< ":\nSum of "
			"each row or column "
		<< n * (n * n + 1) / 2 << ":\n\n";
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)

			// setw(7) is used so that the matrix gets
			
			cout << setw(4) << MAGICSq[i][j] << " ";
		cout << endl;
	}
}

// Driver code
int main()
{

	// Works only when n is odd
	int n = 7;
	MAgic(n);
	return 0;
}

// This code is contributed by rathbhupendra
