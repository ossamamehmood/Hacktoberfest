/*
Author : Rounak Ghosh
GitHub : rounak-ghosh
Institution : GCETTB
Date : 08/10/2022
*/

#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string s = "((a+b))";
    int count = 0;
    stack<char> st;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '(' || s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            st.push(s[i]);
        else if(s[i] == ')')
        {
            if(st.top() == '(')
                count++;
            else if(st.top() == '(' || st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/')
                st.pop();
        }                
    }
    cout << count;
}