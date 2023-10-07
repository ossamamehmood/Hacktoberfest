// Fibonacci Series using Space Optimized Method
#include <bits/stdc++.h>
using namespace std;

int fib(int n)
{
	int a = 0, b = 1, c, i;
	if (n == 0)
		return a;
	for (i = 2; i <= n; i++) {
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

// Driver code
int main()
{
	int n = 9;

	cout << fib(n);
	return 0;
}

// This code is contributed by Code_Mech
