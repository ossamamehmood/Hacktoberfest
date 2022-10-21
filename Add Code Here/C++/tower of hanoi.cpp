

#include <bits/stdc++.h>
using namespace std;

void TOW(int n, char from_pole, char to_pole,
				char aux_pole)
{
	if (n == 0) {
		return;
	}
	TOW(n - 1, from_pole, aux_pole, to_pole);
	cout << "Move circle " << n << " from pole " << from_pole
		<< " to pole " << to_pole << endl;
	TOW(n - 1, aux_pole, to_pole, from_pole);
}


int main()
{
	int N = 3;

	
	TOW(N, 'p', 'q', 'r');
	return 0;
}


