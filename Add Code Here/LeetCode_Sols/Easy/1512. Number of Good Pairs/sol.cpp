class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int ans = 0;
        std::vector<int> count(101, 0);

        for (int n : nums) {
            count[n]++;
        }

        for (int n : count) {
            ans += (n * (n - 1)) / 2;
        }

        return ans;
    }
};
