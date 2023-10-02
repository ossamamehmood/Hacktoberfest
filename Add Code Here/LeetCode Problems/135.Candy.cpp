class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        // create a vector 'choc' to store the number of candies for each child, initialized to 1.
        vector<int> choc(n, 1);

        // First pass: Check ratings from left to right.
        for (int i = 0; i < n - 1; i++) {
            // if the current child's rating is less than the next child's rating, 
            // give the next child more candies than the current child.
            if (ratings[i] < ratings[i + 1]) {
                choc[i + 1] = max(choc[i + 1], choc[i] + 1);
            }
        }

        // second pass, check ratings from right to left.
        for (int i = 0; i < n - 1; i++) {
            // if the current child's rating is less than the previous child's rating,
            // and they don't have more candies than the previous child, give them more candies.
            if (ratings[n - 1 - i] < ratings[n - 2 - i]) {
                choc[n - 2 - i] = max(choc[n - 2 - i], choc[n - 1 - i] + 1);
            }
        }

        int totalCandies = 0;
        // calculate the total number of candies needed by summing up the 'choc' vector.
        for (int i = 0; i < choc.size(); i++) {
            totalCandies += choc[i];
        }

        return totalCandies; // return the minimum number of candies needed.
    }
};
