#include<iostream>
using namespace std;
int main()
{
    int no;
    cout<<"Enter a number:";
    cin>>no;
    if(no==0)
    {
        cout<<"0 is nither positive nor negative"<<endl;
    }
    else if(no>0)
    {
        cout<<no<<" is a Positive Number"<<endl;
    }
    else
    {
        cout<<no<<" is a Negative Number"<<endl;
    }
}