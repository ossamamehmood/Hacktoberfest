#include<iostream>
using namespace std;

int main()
{
    int n,x=0;
    cout<<"Enter a number. \n";
    cin>>n;

    int array[n];
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
        x+=array[i];
    }
    cout<<"The sum of the elements is "<<x;

    return 0;
}