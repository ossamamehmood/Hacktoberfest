#include<bits/stdc++.h>
using namespace std;
int main(){
    stack <int> stack1;
    char s[100];
    cout<<"enter a postfix expression";
    cin>>s;
    int i=0;
    int n1,n2,a;
    while(s[i])
    {
        a=s[i];
        if(isdigit(a))
        {
            a=s[i]-48;
            stack1.push(a);     
        }
        else{
            n1=stack1.top();
            stack1.pop();
            n2=stack1.top();
            stack1.pop();
                
            switch(a)
            {
                case '+':
                a=n1+n2;
                stack1.push(a);
               
                break;
                case '-':
                a=n2-n1;
                stack1.push(a);
                
                break;
                case '*':
                a=n1*n2;
                stack1.push(a);
                
                break;
                case '/':
                a=n2/n1;
                stack1.push(a);
                
                break;
                
            }
        }
        i++;
    }
    cout<<stack1.top();
}
