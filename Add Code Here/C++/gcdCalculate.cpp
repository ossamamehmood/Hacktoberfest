#include<bits/stdc++.h>
using namespace std;
int gcd (int num1, int num2) {
    if (num2 == 0)
        return num1;
    else
        return gcd (num2, num1 % num2);
}
int main()
{
    int num1,num2;
    cout<<"Enter two numbers :";
    cin>>num1>>num2;
    cout<<"GCD  = "<<gcd(num1,num2)<<"\n";
    return 0;
}
