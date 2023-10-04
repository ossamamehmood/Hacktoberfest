class Solution {
public:
    const int MOD = 1e9 + 7;  // Modulus for calculations
    vector<long long> memoization;  // Memoization array to store computed values

    long long calculateOrdersCount(long long remainingPairs) {
        // Base case: No remaining pairs, return 1
        if (remainingPairs == 0)
            return 1;

        // Check if the value is already computed and return it
        if (memoization[remainingPairs] != -1)
            return memoization[remainingPairs];

        // Calculate the number of valid orders for the remaining pairs
        long long currentResult = calculateOrdersCount(remainingPairs - 1) * (2 * remainingPairs - 1) * remainingPairs % MOD;

        // Store the result in the memoization array and return it
        return memoization[remainingPairs] = currentResult;
    }

    int countOrders(int numPairs) {
        // Initialize the memoization array with -1 values
        memoization.resize(numPairs + 1, -1);

        // Calculate and return the count of valid orders
        return calculateOrdersCount(numPairs);
    }
};
