#include<bits/stdc++.h>
using namespace std;
int gcd (int num1, int num2) {
    if (num2 == 0)
        return num1;
    else
        return gcd (num2, num1 % num2);
}
int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}
int main()
{
    int num1,num2;
    cout<<"Enter two numbers :";
    cin>>num1>>num2;
    cout<<"LCM  = "<<lcm(num1,num2)<<"\n";
    return 0;
}
