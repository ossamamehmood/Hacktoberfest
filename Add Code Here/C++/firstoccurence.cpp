//--------------------------first occurence in the array-----------------
#include<iostream>
using namespace std;

//navive
//int firstocc(int a[], int n, int x)
//{
//    for(int i=0;i<n;i++)
//    {
//        if(a[i]==x)
//        return i;
//
//    }
//    return -1;
//
//}

//-------------------------recurrsive binary search approach-----------------
//int firstocc(int a[],int low,int high ,int x)
//{
//    if(low>high)
//    return -1;
//
//    int mid=(low+high)/2;
//
//    if(x<a[mid])
//    return firstocc(a,low,mid-1,x);
//
//    else if(x>a[mid])
//    return firstocc(a,mid+1,high,x);
//
//    else
//    {
//        if(mid==0|| a[mid-1]!=a[mid])
//        return mid;
//        else
//        return firstocc(a,low,mid-1,x);
//
//    }
//
//}


//-------------------------------------- approach 3: iterative binary search-------------------
int firstocc(int a[],int n,int x)
{ 
    int low=0,high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(x<a[mid])
        high=mid-1;

        else if(x>a[mid])
        low=mid+1;

        else
        {
            if(mid==0 || a[mid-1]!=a[mid])
            return mid;
            else
            high=mid-1;

        }
    }
    return -1;

}
int main()
{
    int a[100],n,x;
    cout<<" Enter the size of array :";
    cin>>n;
    cout<<" \n enter the element to be find out:";
    cin>>x;


    cout<<"\n enter the elemnts of an array one by one:";
    for(int i=0;i<n;i++)
    cin>>a[i];

    //int res=firstocc(a,n,x);

    /*int low=0,high=n-1;
    int mid=firstocc(a,low,high,x); */
    int mid=firstocc(a,n,x);
    
    cout<<endl<<mid<<"th index";
    return 0;
    
}