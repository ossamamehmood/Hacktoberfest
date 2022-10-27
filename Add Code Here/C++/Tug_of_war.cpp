


static string allComb = "";
static int minDiff = INT_MAX;


void tugOfWar(int arr[], int n, int idx, vector<int> set1, vector<int> set2, int soset1, int soset2) {
	if (idx == n) {
		int diff = abs(soset1 - soset2);

		if (diff < minDiff) {
			minDiff = diff;

			string ans = "";

			for (int x : set1) ans += " " + to_string(x);
			ans += " " + "$";
			for (int x : set2) ans += " " + to_string(x);

			allComb = ans.substr(1);
		}
		return;
	}

	if (set1.size() < (n + 1) / 2) {
		set1.push_back(arr[idx]);
		solve(arr, n, idx + 1, set1, set2, soset1 + arr[idx], soset2);
		set1.pop_back();
	}

	if (set2.size() < (n + 1) / 2) {
		set2.push_back(arr[idx]);
		solve(arr, n, idx + 1, set1, set2, soset1, soset2 + arr[idx]);
		set2.pop_back();
	}
}


int main() {
	int arr[] = { 23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);

	vector<int> set1, set2;

	tugOfWar(arr, n, 0, set1, set2, 0, 0);
	return 0;
}
