#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       int num,bin;
       cout<<"Enter the number : ";
       cin>>num;
       cout<<"The binary equivalent of " <<num<< " is : ";
       while(num>0)
       {
           bin = num%2;
           cout<<bin;
           num/= 2;
       }
           cout<<endl;

    }
    return 0;
}