// C++ code for Max
// Water Container
#include <iostream>
using namespace std;

int maxArea(int A[], int len)
{
	int area = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			// Calculating the max area
			area = max(area, min(A[j], A[i]) * (j - i));
		}
	}
	return area;
}

// Driver code
int main()
{
	int a[] = { 1, 5, 4, 3 };
	int b[] = { 3, 1, 2, 4, 5 };

	int len1 = sizeof(a) / sizeof(a[0]);
	cout << maxArea(a, len1);

	int len2 = sizeof(b) / sizeof(b[0]);
	cout << endl << maxArea(b, len2);
}
