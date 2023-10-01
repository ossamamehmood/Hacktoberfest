#include<iostream>
using namespace std;
int money(int a, float b=1.79)
{
    return a*b;
}
int main(int argc, char const *argv[])
{
    int n,m;
    cout<<"Enter your Total Policy amount\n";
    cin>>n;
    cout<<"enter multiplier of the money \n";
    cin>>m;
    cout<<"Your total Money is: "<<n<<"and you will get: "<<money(n)<<" rupees"; //Here, default value of 1.79 is used.
    return 0;
}
