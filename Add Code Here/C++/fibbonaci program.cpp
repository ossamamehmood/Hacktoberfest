#include<iostream>
using namespace std;
// github username - ayush91985
// github- https://github.com/ayush91985
int fact(int n)
{
    int factorial=1;
    for(int i=n;i>=1;i--)
    factorial=factorial*i;
    return factorial;
}
int main(){
    int n;
    cout<<"enter the number ";
    cin>>n;
    cout<<"the factorial of the number is "<<fact(n);
    
}