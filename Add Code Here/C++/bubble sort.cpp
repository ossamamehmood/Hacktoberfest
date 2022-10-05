#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array "<<endl;
    cin>>n;
    int arr[n],i,j,pass;
    cout<<"Enter the elements"<<endl;

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Original Array : "<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
           if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        pass++;
    }
    cout<<"New Array : "<<endl;
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Number of pass "<<pass;
    return 0;
}
