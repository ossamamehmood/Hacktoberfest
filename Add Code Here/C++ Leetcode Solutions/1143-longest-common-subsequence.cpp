class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        const int n = text1.length(), m = text2.length(), k = m + 1;

        int* prev = new int[k] ();

        for (int i = 0, j, v; i < n; i++) {
            int* curr = new int[k] ();

            for (j = 0; j < m;) {
                v = j++;
                curr[j] = text1[i] == text2[v] ? prev[v] + 1 : max(prev[j], curr[v]);
            }

            prev = curr;
        }

        return prev[m];
    }
};
