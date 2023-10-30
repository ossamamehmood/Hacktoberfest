#include<iostream>
using namespace std;
int cnt=0;
void toh(int n, char a,char b,char c)
{
    if(n==1)
    {
        cout<<++cnt<<"move 1 disc from"<<a<<"to"<<c<<"\n";
        return;
    }
    else
    {
        toh(n-1,a,c,b);
        cout<<++cnt<<"move 1 disc from"<<a<<"to"<<c<<"\n";
        toh(n-1,b,a,c);
    }
}
int main()
{
    toh(3,'A','B','C');
}
