#include<bits/stdc++.h>
using namespace std;

int Kth_smallest_Number(int arr[], int n, int k)
{
    priority_queue<int>pq;

    for(int i = 0; i<k; i++)
    {
        pq.push(arr[i]);
    }

    for(int i = k; i<n; i++)
    {
        if(arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int main()
{
    int n;
    cout<<"Enter the Size of Heap : "<<endl;
    cin>>n;

    int Heap[n];

    cout<<"Enter the Data in Heap : "<<endl;
    for(int i =0; i<n; i++)
    {
        cin>>Heap[i];
    }

    // smallest element 
    int k;
    cout<<"Enter the Kth Smallest element : ";
    cin>>k;

    cout<<k<<"th Smallest Element is "<<Kth_smallest_Number(Heap, n, k)<<endl; 
    return 0;
}