class Solution {
    public String removeOuterParentheses(String s) {
        StringBuilder sb = new StringBuilder();
        int open = 0, close = 0, br = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '(')
                open++;
            else if(s.charAt(i) == ')')
                close++;
            if(open==close) {
                sb.append(s.substring(br + 1, i));
                br = i + 1;
            }
        }
        return sb.toString();
    }
}