// A naive recursive C++ program to count number of ways to cover
// a distance with 1, 2 and 3 steps
#include<iostream>
using namespace std;

// Returns count of ways to cover 'dist'
int printCountRec(int dist)
{
	// Base cases
	if (dist<0)	 return 0;
	if (dist==0) return 1;

	// Recur for all previous 3 and add the results
	return printCountRec(dist-1) +
		printCountRec(dist-2) +
		printCountRec(dist-3);
}

// driver program
int main()
{
	int dist = 4;
	cout << printCountRec(dist);
	return 0;
}
