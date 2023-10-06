#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD = 1000000007;
        vector<vector<long long>> temp(goal + 1, vector<long long>(n + 1, 0));
        temp[0][0] = 1;

        for (int i = 1; i <= goal; i++) {
            for (int j = 1; j <= n; j++) {
                temp[i][j] = (temp[i][j] + temp[i - 1][j - 1] * (n - j + 1)) % MOD;
                if (j > k) {
                    temp[i][j] = (temp[i][j] + temp[i - 1][j] * (j - k)) % MOD;
                }
            }
        }

        return static_cast<int>(temp[goal][n]);
    }
};
