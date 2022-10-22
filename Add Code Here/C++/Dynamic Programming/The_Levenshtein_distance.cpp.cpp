#include <iostream>
using namespace std;

// Function to find Levenshtein distance between string `X` and `Y`.
// `m` and `n` is the total number of characters in `X` and `Y`, respectively
int dist(string X, int m, string Y, int n)
{
	// base case: empty strings (case 1)
	if (m == 0) {
		return n;
	}

	if (n == 0) {
		return m;
	}

	int cost;

	// if the last characters of the strings match (case 2)
	if (X[m - 1] == Y[n - 1]) {
		cost = 0;
	}
	else {
		cost = 1;
	}

	return min (min(dist(X, m - 1, Y, n) + 1,   // deletion	(case 3a))
			dist(X, m, Y, n - 1) + 1),  		// insertion (case 3b))
			dist(X, m - 1, Y, n - 1) + cost);   // substitution (case 2 & 3c)
}

int main()
{
	string X = "kitten", Y = "sitting";

	cout << "The Levenshtein distance is " << dist(X, X.length(), Y, Y.length());

	return 0;
}