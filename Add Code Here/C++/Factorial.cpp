#include<iostream>

using namespace std;

int fact(int n)
{
    if(n==0) return 1;

    return n*fact(n-1);
}

int main()
{
    int num;
    cout<<"Enter A number ";
    cin>>num;
    int ans=fact(num);
    cout<<"The factorial of "<<num<<" is :-"<<ans<<endl;
}