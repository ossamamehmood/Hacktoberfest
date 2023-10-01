#include<iostream>
using namespace std;
void g();
int sum(int,int);
int main(int argc, char const *argv[])
{
    int m,n;
    cout<<"Enter 1st no.\n";
    cin>>m;
    cout<<"Enter 2nd no.\n";
    cin>>n;
    cout<<"The sum is: "<<sum(m,n)<<endl;
    g();

    return 0;
}
int sum(int a , int b)
{
    int sum =a+b;
    return sum;
}
void g()
{
    cout<<"Code is Written by Anshul Kunwar";
}
