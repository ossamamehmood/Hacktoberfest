#include<iostream>
using namespace std;
int main()
{
    cout<<"Enter a number: ";
    int check;
    cin>>check;
    if(check % 2 == 0)
    {
        cout<<check<<" is an EVEN number"<<endl;
    }
    else
    {
        cout<<check<<" is ODD number"<<endl;
    }
}