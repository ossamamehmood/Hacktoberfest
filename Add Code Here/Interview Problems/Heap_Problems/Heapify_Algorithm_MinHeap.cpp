#include<bits/stdc++.h>
using namespace std;

/* Min Heap look like

            50
           /  \
         52    55
        /  \
       54   53 
    
    I/P : 54 53 55 52 50 
    O/P : 50 52 55 54 53
*/

void Heapify_MinHeap(int Heap[], int n, int i)
{
    int smallest = i;
    int Left = 2 * i + 1;
    int Right = 2 * i + 2;

    if(Left < n && Heap[smallest] > Heap[Left])
    {
        smallest = Left;
    }

    if(Right < n && Heap[smallest] > Heap[Right])
    {
        smallest = Right;
    }

    if(smallest != i)
    {
        swap(Heap[smallest], Heap[i]);
        Heapify_MinHeap(Heap, n, smallest);
    }
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
    
    cout<<endl<<"Before Heapify : "<<endl;
    for(int i =0; i<n; i++)
    {
        cout<<Heap[i]<<" ";
    }
    
    // function call
    // in ths loop we don't include the leaf nodes  
    for(int i = n/2-1; i>=0; i--)
    {
        Heapify_MinHeap(Heap, n, i);
    }

    cout<<endl<<"After Heapify : "<<endl;
    for(int i =0; i<n; i++)
    {
        cout<<Heap[i]<<" ";
    }    
    return 0;
}