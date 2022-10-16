#include<iostream>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a+b+c <=d)
        {
            cout<<1<<endl;
        }
        else if(a + b <=d)
        {
            cout<<2<<endl;
        }
        else{
            cout<<3<<endl;
        }
    }
}