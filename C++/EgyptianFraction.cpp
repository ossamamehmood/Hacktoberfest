/* C++ program to print a fraction in Egyptian Form using Greedy Algorithm*/
/*Efficient Approach */
#include <bits/stdc++.h>
using namespace std;
void egyptianFraction(int n, int d)
{
//When Both Numerator and denominator becomes zero then we simply return;
	if (d == 0 || n == 0)
		return;
	if (d % n == 0) {
		cout << "1/" << d / n;
		return;
	}
	if (n % d == 0) {
		cout << n / d;
		return;
	}
	if (n > d) {
		cout << n / d << " + ";
		egyptianFraction(n % d, d);
		return;
	}
	int x = d / n + 1;
	cout << "1/" << x << " + ";
	egyptianFraction(n * x - d, d * x);
}
int main()
{
	int numerator = 6, denominator = 14;
	cout << "Egyptian Fraction representation of "
		<< numerator << "/" << denominator << " is"
		<< endl;
	egyptianFraction(numerator, denominator);
	return 0;
}
