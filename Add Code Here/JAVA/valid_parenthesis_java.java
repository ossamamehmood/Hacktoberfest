import java.util.Stack;

public class LeetCode20 {
    public boolean isValid(String s) {

        //creates new stack to store the brackets
        Stack<Character> temp = new Stack<Character>();

        //iterates through the string
        for (int i = 0; i<s.length(); i++) {

            //initiating the charAt as a character to prevent errors when pushing to stack
            char par = s.charAt(i);

            //checking if the character is an opening string. If so, push the character into the stack
            if (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{') {
                temp.push(par);
            } else {

                //checks if stack is empty initially, as in, if nothing is added then there must be no opening bracket, returning false
                if (temp.empty()) {
                    return false;
                }

                //this section checks if the top of the stack matches the closing brackets. If so, it will pop them off the stack
                if (s.charAt(i) == ')' && temp.peek() == '('){
                    temp.pop();
                }

                else if (s.charAt(i) == ']' && temp.peek() == '[') {
                    temp.pop();
                }

                else if (s.charAt(i) == '}' && temp.peek() == '{') {
                    temp.pop();

                }

                // If nothing from the top matches, that means the closing brackets didn't match the top opening bracket in the stack.
                // Which means that it is a rogue closing bracket, thus breaking out of the whole loop. This leaves the stack not empty, returning false
                else {
                    break;
                }

            }

        }

        return temp.empty();
    }

}
