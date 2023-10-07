// This interview question was asked in Microsoft
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
            stack.push(s[i]);
            else if(stack.empty() ||
                    (s[i]==')' && stack.top()!='(')||
                    (s[i]==']' && stack.top()!='[') ||
                    (s[i]=='}' && stack.top()!='{' ))
            {
                return false;
            }
            else
            {
                stack.pop();
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution solution;
    string input;
    
    cout << "Enter a string containing parentheses, curly braces, and square brackets: ";
    cin >> input;
    
    if (solution.isValid(input)) {
        cout << "The input string is valid." << endl;
    } else {
        cout << "The input string is not valid." << endl;
    }
    
    return 0;
}

