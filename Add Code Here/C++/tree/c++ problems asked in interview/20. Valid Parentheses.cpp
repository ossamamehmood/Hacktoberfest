Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 
Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
Example 4:

Input: s = "([)]"
Output: false
Example 5:

Input: s = "{[]}"
Output: true
  
Solution :
Time Complexity : O(n) where s is the length of the string 
Space Complexity : O(n) where s is the length of the string 

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(auto c:s)
        {
            switch(c)
            {
                case '{' : stk.push('}');
                    break;
                case '[' : stk.push(']');
                    break;
                case '(' : stk.push(')');
                    break;
                default : if(stk.size()==0 || c != stk.top())
                    return false;
                    else
                        stk.pop();
            }
        }
        return stk.size()==0;
    }
};
