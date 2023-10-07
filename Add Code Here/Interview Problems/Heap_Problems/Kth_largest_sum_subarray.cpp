#include<bits/stdc++.h>
using namespace std;

int Largest_Sum_Subarray(vector<int>&Heap, int k)
{
    vector<int>Ans;
    
    for(int i = 0; i<Heap.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < Heap.size(); j++)
        {
            sum += Heap[j];

            Ans.push_back(sum);
        }
    }

    sort(Ans.begin(), Ans.end());
    return Ans[Ans.size() - k];
}

int main()
{
    int n, val;
    cout<<"Enter the Size of Heap : "<<endl;
    cin>>n;

    vector<int>Heap;
    cout<<"Enter the Data in Heap : "<<endl;
    for(int i =0; i<n; i++)
    {
        cin>>val;
        Heap.push_back(val);
    }
    
    int k;
    cout<<"Enter the Kth Sum Subarray : ";
    cin>>k;

    cout<<Largest_Sum_Subarray(Heap, k);

    return 0;
}