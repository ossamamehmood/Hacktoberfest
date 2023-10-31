#include <iostream>
#include <vector>

using namespace std;

bool isSubsetSumPossible(int n, int target, vector<int> &numbers) {
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j];

            if (j >= numbers[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - numbers[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    vector<int> numbers = {1, 2, 3, 4};
    int target = 4;
    int n = numbers.size();

    if (isSubsetSumPossible(n, target, numbers)) {
        cout << "Subset with the given target found";
    } else {
        cout << "Subset with the given target not found";
    }

    return 0;
}
