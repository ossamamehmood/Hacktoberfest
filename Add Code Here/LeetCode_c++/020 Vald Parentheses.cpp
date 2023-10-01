class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (c == ')' && stk.top() == '(') {
                    stk.pop();
                } else if (c == '}' && stk.top() == '{') {
                    stk.pop();
                } else if (c == ']' && stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
