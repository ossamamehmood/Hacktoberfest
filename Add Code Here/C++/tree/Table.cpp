#include<iostream>
using namespace std;

int main()
{
    int i;
    int num;
    int table;
    cout<<"Enter the table which you want = ";
    cin>>num;

    for(i=1;i<=10;i++)
    {
        table=i*num;
        cout<<num<<" x "<<i<<" = "<<table<<endl;
    }
    return 0;
} 
