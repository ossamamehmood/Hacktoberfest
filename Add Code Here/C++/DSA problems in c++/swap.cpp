#include<iostream>
using namespace std;

void swap_call_by_value(int x,int y)
{
    int c=x;
    x=y;
    y=c;
    cout<<"\nInside Function After Swapping, Value of :: \n\tA = "<<x<<"\tB = "<<y<<"\n";
}

void swap_call_by_reference(int &x, int &y)
{
    int c = x;
    x=y;
    y=c;
    cout<<"\nInside Function After Swapping, Value of :: \n\tA = "<<x<<"\tB = "<<y<<"\n";
}

int main()
{
    int a,b;
    cout<<"\nEnter value of first number (a) = ";
    cin>>a;
    cout<<"\nEnter value of second number (b) = ";
    cin>>b;
    cout<<"\n==== Call by value ====\n";
    cout<<"\nBefore Swapping, Value of :: \n\ta = "<<a<<"\tb = "<<b<<"\n";
    swap_call_by_value(a,b);
    cout<<"\nOutside Function After Swapping, Value of :: \n\ta = "<<a<<"\tb = "<<b<<"\n";
    cout<<"\n\n==== Call by reference ====\n";
    cout<<"\nBefore Swapping, Value of :: \n\ta = "<<a<<"\tb = "<<b<<"\n";
    swap_call_by_reference(a,b);
    cout<<"\n Outside Function After Swapping, Value of :: \n\ta = "<<a<<"\tb = "<<b<<"\n";
    return 0;
}
