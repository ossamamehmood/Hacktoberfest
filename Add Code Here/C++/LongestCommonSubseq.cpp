#include <iostream>
#include <string>
using namespace std;
 
// Function to find the length of the longest common subsequence of
// sequences `X[0…m-1]` and `Y[0…n-1]`
int LCSLength(string X, string Y, int m, int n)
{
    // return if the end of either sequence is reached
    if (m == 0 || n == 0) {
        return 0;
    }
 
    // if the last character of `X` and `Y` matches
    if (X[m - 1] == Y[n - 1]) {
        return LCSLength(X, Y, m - 1, n - 1) + 1;
    }
 
    // otherwise, if the last character of `X` and `Y` don't match
    return max(LCSLength(X, Y, m, n - 1), LCSLength(X, Y, m - 1, n));
}
 
int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
 
    cout << "The length of the LCS is " <<
            LCSLength(X, Y, X.length(), Y.length());
 
    return 0;
}
