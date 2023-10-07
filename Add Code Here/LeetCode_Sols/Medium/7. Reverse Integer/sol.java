public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public int reverse(int x) {
            String s = String.valueOf(x);
            StringBuilder reversed = new StringBuilder();

            int start = s.charAt(0) == '-' ? 1 : 0;

            for (int i = s.length() - 1; i >= start; i--) {
                reversed.append(s.charAt(i));
            }

            try {
                return x >= 0 ? Integer.parseInt(reversed.toString()) : -Integer.parseInt(reversed.toString());
            } catch (NumberFormatException e) {
                return 0;
            }
        }
    }
}
