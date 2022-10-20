#include <iostream>
#include <stack>
#include <string>
using namespace std;
int p(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
int main(){
	stack<char> s1;
	string name;
	cout<<"Conversion infix to postfix"<<endl;
	cout<<"Enter the String : "<<endl;
	getline(cin, name);
	int size=name.length();
	int count=0;
	for(int i=0;i<size;i++){
	     if ((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9')){
	     	cout<<name[i];
		 }else if (name[i] == '('||name[i]=='['||name[i]=='{'){
            s1.push(name[i]);
        }
        else if (name[i] == ')') {
            while (s1.top() != '(') {
                cout<<s1.top();
                s1.pop();
            }
            s1.pop();
        }
        else if(name[i]==']'){
            while (s1.top() != '[') {
                cout<< s1.top();
                s1.pop();
            }
            s1.pop();
        }
        else if(name[i]=='}'){
            while (s1.top() != '{') {
                cout<< s1.top();
                s1.pop();
            }
           s1.pop();
          }
        else {
            while (!s1.empty() && p(name[i]) <= p(s1.top())) {
                cout<< s1.top();
                s1.pop();
            }
            s1.push(name[i]);
        }
	}
	while (!s1.empty()) {
        cout<< s1.top();
        s1.pop();
    }
	return 0;
}
