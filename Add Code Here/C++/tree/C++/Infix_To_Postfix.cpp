#include<bits/stdc++.h>
using namespace std;


int value(char c) {
    if(c == '^')
        return 3;
    else if(c == '/' || c=='*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}
void infixToPostfix(string s) {
    vector<char> arr;
    string answer;
    for(int i = 0; i < s.length(); i++) {
        char c = s[i]; 
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            answer += c;
        else if(c == '(')
            arr.push_back('(');
        else if(c == ')') {
            while(arr[arr.size()-1] != '(')
            {
                answer += arr[arr.size()-1];
                arr.pop_back();
            }
            arr.pop_back();
        }
        else {
            while(!arr.empty() && value(s[i]) <= value(arr[arr.size()-1])) {
                answer += arr[arr.size()-1];
                arr.pop_back(); 
            }
            arr.push_back(c);
        }
    }
    while(!arr.empty()) {
        answer += arr[arr.size()-1];
        arr.pop_back();
    } 
    cout << answer << endl;
}
int main() {
    string exp ;
    cout<<"Enter the expression to be converted: "<<endl;
    cin>>exp;
    infixToPostfix(exp);
    return 0;
}