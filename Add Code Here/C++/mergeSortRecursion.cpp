#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// TC = O(nlogn)
void merge(int *arr,int s,int e)
{
    int mid=(s+e)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int *a=new int[len1];
    int *b=new int[len2];

    int mainArrayIndex=s;
    for(int i=0;i<len1;i++)
    {
        a[i]=arr[mainArrayIndex++];
    }
    mainArrayIndex=mid+1;
    for(int i=0;i<len2;i++)
    {
        b[i]=arr[mainArrayIndex++];
    }

    //merge 2 sorted array
    int index1=0;
    int index2=0;
    mainArrayIndex=s;

    while (index1<len1 && index2<len2)  
    {
        if(a[index1]<b[index2])
        {
            arr[mainArrayIndex++]=a[index1++];
        }
        else
        {
           arr[mainArrayIndex++]=b[index2++];
        }
    }
    while(index1<len1)
    {
        arr[mainArrayIndex++]=a[index1++];
    }
    while (index2<len2)
    {
        arr[mainArrayIndex++]=b[index2++];
    }
    delete []a;
    delete []b;
}
void sort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=s+(e-s)/2;
    //left part sort
    sort(arr,s,mid);
    //right part sort
    sort(arr,mid+1,e);

    //merge
    merge(arr,s,e);
}
int main()
{
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,0,n-1);
    cout<<"Sorted array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}