#include<iostream>
using namespace std;
int secondsmallest(int arr[],int n)
{
    int small=arr[0];
    int secondsmall=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<small)
        {
            secondsmall=small;
            small=arr[i];
        }
        else if(arr[i]!=small && arr[i]<secondsmall )
        {
            secondsmall=arr[i];
        }
    }
    return secondsmall;
}

int main() {
    int arr[] = {2,5,1,3,0,42,54};
    int n=sizeof(arr)/sizeof(arr[0]);
    secondsmallest(arr,n);


}
