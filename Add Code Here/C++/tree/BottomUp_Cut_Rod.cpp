#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb emplace_back
#define pp pop_back
#define powof2(x) (x && !(x & (x-1)))

#define INF	1000000000+10
#define mod 1000000007

const int N = 100005;
int dp[N];

int BottomUp(int P[], int n) {
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		int q = 0;
		for(int j = 1; j <= i; j++) {
			q = max(q, P[j] + dp[i-j]);
		}
		dp[i] = q;
	}
	return dp[n];
}
void solve() {
	int n, k; cin >> n >> k;	
	int P[k];
	for(int i = 1; i <= k; i++) {
		cin >> P[i];
	}
	int res = BottomUp(P, n);
	cout << res << "\n";
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	t = 1;
	// cin >> t;
	while(t--) {
		solve();
	}

	return 0;
}