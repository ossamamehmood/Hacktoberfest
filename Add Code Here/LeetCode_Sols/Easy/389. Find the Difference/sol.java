public class sol {
    public static void main(String[] args) {
        // call your fn here
    }

    class Solution {
        public char findTheDifference(String s, String t) {
            int sum1 = helper(s);
            int sum2 = helper(t);
            int diff = sum2 - sum1;
            return (char) diff;
        }

        int helper(String s) {
            return s.chars().sum();
        }

    }
}