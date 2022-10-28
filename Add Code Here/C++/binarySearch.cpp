#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,x,low,mid,high,val;
    vector<int> V;
    cout<<"Enter The Number Of Elements"<<endl;
    cin>>n;
    cout<<"Enter The Elements"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>x;
        V.push_back(x);
    }
    cout<<"Sorted Array:"<<endl;
    sort(V.begin(),V.end());
    for(i=0;i<n;i++)
    {
        cout<<V[i]<<" ";
    }
    cout<<endl;
    cout<<"Enter The Element To Be Searched"<<endl;
    cin>>val;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(V[mid]==val)
        {
             break;
        }
        else if(V[mid]>val)
        {
            high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    if(low>high)
    {
        cout<<"Element Not Present"<<endl;
    }
    else
    {
        cout<<"Element Present At Index "<<mid<<endl;
    }
    return 0;
}
