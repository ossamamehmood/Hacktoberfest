// C++ program to find nth ugly number
#include <iostream>
using namespace std;

// This function divides a by greatest
// divisible power of b
int maxDivide(int a, int b)
{
	while (a % b == 0)
		a = a / b;
		
	return a;
}

// Function to check if a number is ugly or not
int isUgly(int no)
{
	no = maxDivide(no, 2);
	no = maxDivide(no, 3);
	no = maxDivide(no, 5);

	return (no == 1) ? 1 : 0;
}

// Function to get the nth ugly number
int getNthUglyNo(int n)
{
	int i = 1;
	
	// Ugly number count
	int count = 1;

	// Check for all integers untill ugly
	// count becomes n
	while (n > count)
	{
		i++;
		if (isUgly(i))
			count++;
	}
	return i;
}

// Driver Code
int main()
{
	
	// Function call
	unsigned no = getNthUglyNo(150);
	cout << "150th ugly no. is " << no;
	return 0;
}

// This code is contributed by shivanisinghss2110
