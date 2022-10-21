// C++ program to print envolepe
// Contributed by
// Name: Shubham
// GitHub Name: tiwarishubham635
// GitHub profile: https://github.com/tiwarishubham635
// Hacktoberfest 2022

/*
Input: 7
Output:

****************
* ************ *
*  **********  *
*   ********   *
*    ******    *
*     ****     *
*      **      *
*      **      *
*     ****     *
*    ******    *
*   ********   *
*  **********  *
* ************ *
****************

*/

#include <bits/stdc++.h>
using namespace std;

void envolepe_pattern(int n)
{
	int i, j;
	
	// This is upper half of pattern
	for (i = 1; i <= n; i++)
	{
	    cout<<"*";
	    // Left part of pattern
		for (j = 1; j <= n; j++)
		{
			if (i > j)
				cout << " ";
			else
				cout << "*";
		}
		
		// Right part of pattern
		for (j = n; j >=1; j--)
		{
			if (i > j)
				cout << " ";
			else
				cout << "*";
		}
		cout<<"*"<<endl;
	}

	// This is lower half of pattern
	for (i = n; i >=1; i--)
	{
	    cout<<"*";
	    // Left part of pattern
		for (j = 1; j <= n; j++)
		{
			if (i > j)
				cout << " ";
			else
				cout << "*";
		}
		
		// Right part of pattern
		for (j = n; j >=1; j--)
		{
			if (i > j)
				cout << " ";
			else
				cout << "*";
		}
		cout<<"*"<<endl;
	}
}

int main()
{
    int n = 7; // change value to print for n
	envolepe_pattern(n);
	return 0;
}