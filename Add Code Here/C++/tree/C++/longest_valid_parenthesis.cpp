#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string s) {

    /*
        we will be using stack and store index of the character
        
        every time we find a pair for top of stack 
        we will pop out and find the length 
        after poping, the top element is the index from where the last time parenthesis becomes invalid
        so it will become valid for the "length = current-index - top of stack " 

        otherwise push the index into the stack.

    */
        stack<int> stk;
        int len = 0;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            
            if(!stk.empty()and s[stk.top()] == '(' and s[i] == ')') {
                int top = stk.top();
                stk.pop();
                len = max(len, i- (stk.empty() ? -1 : stk.top()));
            }
            else {
                stk.push(i);
            }
        }
        return len;
}

int main() {
    string str = "((((()))))((()))))(((())()()()()";
    cout<<longestValidParentheses(str);
}