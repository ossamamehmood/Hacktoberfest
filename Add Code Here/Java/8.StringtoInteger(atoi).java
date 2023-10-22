class Solution {
    public int myAtoi(String str) {
        if (str == null || str.length() < 1) {
            return 0;
        }
        final int INT_MAX = 2147483647;
        final int INT_MIN = -2147483648;
        str = str.replaceAll("^\\s+", "");
        int i = 0;
        boolean isNegative = str.startsWith("-");
        boolean isPositive = str.startsWith("+");
        if (isNegative) {
            i++;
        } else if (isPositive) {
            i++;
        }
        double number = 0;
        while (i < str.length() && str.charAt(i) >= '0' && str.charAt(i) <= '9') {
            number = number * 10 + (str.charAt(i) - '0');
            i++;
        }
        number = isNegative ? -number : number;
        if (number < INT_MIN) {
            return INT_MIN;
        }
        if (number > INT_MAX) {
            return INT_MAX;
        }
        return (int) number;
    }
}