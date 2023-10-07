// Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
// Note: Answer can be very large, so, ouput will be answer modulo 109+7.

// Input:
// s = "abc"
// Output:
// 8
// Explanation:
// The seven distinct subsequences are "", "a", "ab", "ac", "abc", "b", "bc" and "c" .

#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1000000007;

int countDistinctSubsequences(string s) {
    int n = s.length();
    
    // Create a table to store the count of distinct subsequences.
    vector<long long> dp(n + 1, 0);

    // Empty subsequence is always a valid subsequence.
    dp[0] = 1;

    // To store the last position of each character in the string.
    vector<int> lastOccurrence(256, -1);

    for (int i = 1; i <= n; i++) {
        // Number of distinct subsequences ending at position i.
        dp[i] = (2 * dp[i - 1]) % MOD;

        // If s[i-1] has appeared before, subtract the count of subsequences
        // that end at the previous occurrence of s[i-1].
        if (lastOccurrence[s[i - 1]] != -1) {
            dp[i] = (dp[i] - dp[lastOccurrence[s[i - 1]] - 1] + MOD) % MOD;
        }

        // Update the last occurrence of s[i-1].
        lastOccurrence[s[i - 1]] = i - 1;
    }

    // Take modulo 10^9+7.
    return dp[n];
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = countDistinctSubsequences(s);
    cout << "Number of distinct subsequences: " << result << endl;

    return 0;
}
