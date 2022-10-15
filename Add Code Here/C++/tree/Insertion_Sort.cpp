#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int a[],int n)
{
    int i,cur,j;
    for(i=1; i<n;i++)
    {
        cur=a[i];
        j=i-1;
        while(j>=0 && a[j]>cur)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=cur;
    }
    cout<<"Sorted Element\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{
    int a[]={22,89,41,90,43,76,55};
    int n = sizeof(a)/sizeof(a[0]);
    insertion_sort(a,n);
    return 0;
}
