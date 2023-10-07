#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> arr(n + 1, -1);
        return std::min(solve(cost, arr, 0), solve(cost, arr, 1));
    }

    int solve(vector<int>& cost,vector<int>& arr, int i) {
        if (i >= cost.size()) return 0;
        if (arr[i] != -1) return arr[i];
        int a = cost[i] + solve(cost, arr, i + 1);
        int b = cost[i] + solve(cost, arr, i + 2);
        return arr[i] = min(a, b);
    }
};
