public class sol {
    public static void main(String[] args) {
        // call the fn here
    }
}

class Solution {
    public boolean isSubsequence(String s, String t) {
        int n1 = s.length();
        int n2 = t.length();

        if (n1 < 1)
            return true;
        int i = 0;
        int j = 0;

        while (i < n2) {
            if (t.charAt(i) == s.charAt(j)) {
                j++;
            }
            i++;
            if (j == n1)
                return true;
        }
        return false;
    }
}