

#include <bits/stdc++.h>
using namespace std;

string solve(string s) {
    int n = s.length();
    bool flag = false, ng = false;
    for(int i=0;i<n;i++) {
        if(s[i] == '(') {
            flag = true;
            if(s[i-1] == '-')
            ng = true;
        }
        if(s[i] == ')') {
            flag = false;
            ng = false;
        }
        if(s[i] == '+' && ng && flag)
        s[i] = '-';
        else if(s[i] == '-' && ng && flag)
        s[i] = '+';
    }
    string s1 = "";
    for(int i=0;i<n;i++) {
        if(s[i] != '(' && s[i] != ')')
        s1 += s[i];
    }
    return s1;
}

int main() {
    string s;
    cin >> s;
    cout << solve(s) << endl;
    return 0;
}
