#include <bits/stdc++.h>
using namespace std;

bool checkSorted(int n, queue<int>& q)
{
	stack<int> stk;
	int expected = 1;
	int fnt;
	
	while (!q.empty()) {
		fnt = q.front();
		q.pop();

		if (fnt == expected)
			expected++;

		else {
		
			if (stk.empty()) {
				stk.push(fnt);
			}

		
			else if (!stk.empty() && stk.top() < fnt) {
				return false;
			}

		
			else
				stk.push(fnt);
		}

		
		while (!stk.empty() && stk.top() == expected) {
			stk.pop();
			expected++;
		}
	}

	if (expected - 1 == n && stk.empty())
		return true;

	return false;
}

int main()
{
	queue<int> q;
	q.push(5);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);

	int n = q.size();

	(checkSorted(n, q) ? (cout << "Yes") :
						 (cout << "No"));

	return 0;
}
