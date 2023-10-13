class Solution {
    public int integerBreak(int n) {
       if (n == 2) {
            return 1;
        }
        if (n == 3) {
            return 2;
        }

        // Try to divide n into as many threes as possible
        int threes = n / 3;
        int remainder = n % 3;

        if (remainder == 1) {
            threes -= 1; // remove 3 * 1
            remainder = 4; // create 2 * 2
        } else if (remainder == 0) {
            remainder = 1; // when remainder is 0, set 1 which doesn't affect your answer.
        }

        return (int) (Math.pow(3, threes) * remainder);        
    }
}
