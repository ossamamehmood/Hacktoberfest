// C++ program to find sum of array elements
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, sum=0;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    cout<<"The sum of array elements is: "<<sum;
    return 0;
}
