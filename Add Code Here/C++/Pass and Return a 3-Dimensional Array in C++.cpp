#include <bits/stdc++.h>
using namespace std;

// Parameter passed as reference
void display(vector<vector<vector<char> > >& ch)
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				cout << "ch[" << i << "][" << j << "]["
					<< k << "] = " << ch[i][j][k] << endl;
			}
		}
	}
}

int main()
{
	vector<vector<vector<char> > > ch
		= { { { 'a', 'b' }, { 'c', 'd' } },
			{ { 'e', 'f' }, { 'g', 'h' } } };

	// Function to call function by passing as parameter
	display(ch);
	return 0;
}
