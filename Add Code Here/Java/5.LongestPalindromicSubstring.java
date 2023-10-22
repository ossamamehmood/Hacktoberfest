class Solution {
    public String longestPalindrome(String s) {
        String updatedString = getUpdatedString(s);
        int length = 2 * s.length() + 1;
        int[] p = new int[length];
        int c = 0;
        int r = 0;
        int maxLength = 0;
        int position = -1;
        for (int i = 0; i < length; i++) {
            int mirror = 2 * c - i;
            if (i < r) {
                p[i] = Math.min(r - i, p[mirror]);
            }
            int a = i + (1 + p[i]);
            int b = i - (1 + p[i]);
            while (a < length && b >= 0 && updatedString.charAt(a) == updatedString.charAt(b)) {
                p[i]++;
                a++;
                b--;
            }
            if (i + p[i] > r) {
                c = i;
                r = i + p[i];
            }
            if (maxLength < p[i]) {
                maxLength = p[i];
                position = i;
            }
        }
        int offset = p[position];
        StringBuilder result = new StringBuilder();
        for (int i = position - offset + 1; i <= position + offset - 1; i++) {
            if (updatedString.charAt(i) != '#') {
                result.append(updatedString.charAt(i));
            }
        }
        return result.toString();
    }

    private String getUpdatedString(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            sb.append("#").append(s.charAt(i));
        }
        sb.append("#");
        return sb.toString();
    }
}
