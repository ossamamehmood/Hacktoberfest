import java.util.Stack;

public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public String removeDuplicateLetters(String s) {
            Stack<Character> stack = new Stack<>();
            boolean[] inStack = new boolean[26];
            int[] lastIndex = new int[26];

            for (int i = 0; i < s.length(); i++) {
                lastIndex[s.charAt(i) - 'a'] = i;
            }

            for (int i = 0; i < s.length(); i++) {
                char ch = s.charAt(i);

                if (inStack[ch - 'a']) {
                    continue;
                }

                while (!stack.isEmpty() && ch < stack.peek() && i < lastIndex[stack.peek() - 'a']) {
                    inStack[stack.pop() - 'a'] = false;
                }

                stack.push(ch);
                inStack[ch - 'a'] = true;
            }

            StringBuilder result = new StringBuilder();
            for (char ch : stack) {
                result.append(ch);
            }

            return result.toString();
        }
    }

}
