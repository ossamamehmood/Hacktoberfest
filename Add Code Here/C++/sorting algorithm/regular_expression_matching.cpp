//Given two strings S and P where S consists of only lowercase English alphabets while P consists of lowercase English alphabets as well as special characters ‘.’ and ‘*’


#include <iostream>
#include <vector>
using namespace std;
 
bool isMatch(string s, string p) {
    int rows = s.length();
    int columns = p.length();
 
    // Base conditions
    if (rows == 0 && columns == 0) {
        return true;
    }
    if (columns == 0) {
        return false;
    }
 
    // DP array
    vector<vector<bool>> dp(rows + 1, vector<bool>(columns + 1, false));
 
    // Empty string and empty pattern are a match
    dp[0][0] = true;
 
    // Deals with patterns with *
    for (int i = 2; i <= columns; i++) {
        if (p[i - 1] == '*') {
            dp[0][i] = dp[0][i - 2];
        }
    }
 
    // For remaining characters
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];
            } else if (j > 1 && p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];
                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
            }
        }
    }
    return dp[rows][columns];
}
 
int main() {
    cout << boolalpha << isMatch("aab", "a.*") << endl;
    return 0;
}