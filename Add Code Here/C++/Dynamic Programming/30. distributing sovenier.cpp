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
bool partition_search(const vector<long long>& A, int index,vector<long long>& partitions, long long target) {
	if (index >= A.size()) return true;
	for (size_t i = 0; i < partitions.size(); i++) {
		if (partitions[i] + A.at(index) <= target) {
			partitions[i] += A.at(index);
			if (partition_search(A, index + 1, partitions, target)) {
				return true;
			}
			partitions[i] -= A.at(index);
		}
	}
	return false;
}

bool partition3(vector<long long>& A) {
	long long n = accumulate(A.begin(), A.end(), 0);
	if (n % 3 != 0 or A.size() < 3 or *max_element(A.begin(), A.end()) > n / 3) {
		return false;
	}

	sort(A.begin(), A.end());
	reverse(A.begin(), A.end());
	vector<long long> partitions(3, 0);
	return partition_search(A, 0, partitions, n / 3);
}

int main() {
	int n;
	cin >> n;
	vector<long long> A(n);
	for (size_t i = 0; i < A.size(); ++i) cin >> A[i];
	cout << partition3(A) <<endl;
	return 0;
}

