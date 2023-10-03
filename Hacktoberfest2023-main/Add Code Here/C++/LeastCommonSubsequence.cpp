#include <iostream>
#include <string>

using namespace std;

string findLongestCommonSubsequence(const string& text1, const string& text2, int dp[][11])
{
    int m = text1.length();
    int n = text2.length();

    string lcs;
    int i = 0, j = 0;

    while (i < m && j < n)
    {
        if (text1[i] == text2[j])
        {
            lcs += text1[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] >= dp[i][j + 1])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return lcs;
}

int longestCommonSubsequence(const string& text1, const string& text2)
{
    int m = text1.length();
    int n = text2.length();

    const int MAX_M = 10;
    const int MAX_N = 10;

    int dp[MAX_M + 1][MAX_N + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (text1[i] == text2[j])
            {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    string lcs = findLongestCommonSubsequence(text1, text2, dp);
    cout << "Longest Common Subsequence: " << lcs << endl;

    int result = dp[0][0];

    return result;
}

int main()
{
    string text1, text2;

    cout << "Enter the first string: ";
    cin >> text1;

    cout << "Enter the second string: ";
    cin >> text2;

    int result = longestCommonSubsequence(text1, text2);
    cout << "Length of longest common subsequence: " << result << endl;

    return 0;
}
