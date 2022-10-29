#include<bits/stdc++.h>
#define        ll        long long int
#define        ls        unsigned long long
#define         eps       1e-9
#define         M_E      2.718281828
#define         M_PI     3.1416
#define        MAX       500
#define        frin          for(ll i=0;i<n;i++)
#define        frjn          for(ll j=0;j<n;j++)
const int   mod=1e9+7;
using namespace std;
int optimal_weight(int W, const vector<int> &w) {
	vector<vector<int>> values(w.size() + 1, vector<int>(W + 1));
	for (size_t i = 0; i <= W; i++) values[0][i] = 0;
	for (size_t i = 0; i <= w.size(); i++) values[i][0] = 0;

	for (size_t i = 1; i <= w.size(); i++) {
		for (size_t j = 1; j <= W; j++) {
			if (j >= w[i - 1]) {
				values[i][j] = max(w[i - 1] + values[i - 1][j - w[i - 1]],
								   values[i - 1][j]);
			} else {
				values[i][j] = values[i - 1][j];
			}
		}
	}

	return values[w.size()][W];
}

int main() {
	int n, W;
	cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++)cin >> w[i];
	cout << optimal_weight(W, w) <<endl;
	return 0;
}
