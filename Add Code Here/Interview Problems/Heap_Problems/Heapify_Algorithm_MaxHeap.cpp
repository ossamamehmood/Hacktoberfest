#include<bits/stdc++.h>
using namespace std;

/* Min Heap look like

            50
           /  \
         52    55
        /  \
       54   53 

    I/P : 54 53 55 52 50 
    O/P : 55 53 54 52 50
*/

void Heapify(int Heap[], int n, int i)
{
    int largest = i;
    int LeftChild = 2 * i;
    int RightChild = 2 * i + 1;

    // check for left child node
    if(LeftChild < n && Heap[largest] < Heap[LeftChild])
    {
        largest = LeftChild;
    }

    // check for right child node
    if(RightChild < n && Heap[largest] < Heap[RightChild])
    {
        largest = RightChild;
    }

    
    // check for largest is updated or not
    if(largest != i)
    {
        swap(Heap[largest], Heap[i]);

        // check for another level 
        Heapify(Heap, n, largest);
    }
}

int main()
{
    int n;
    cout<<"Enter the Size of Heap : "<<endl;
    cin>>n;

    int Heap[n];
    cout<<"Enter the Data in Heap : "<<endl;
    for(int i =1; i<=n; i++)
    {
        cin>>Heap[i];
    }
    
    cout<<endl<<"Before Heapify : "<<endl;
    for(int i =1; i<=n; i++)
    {
        cout<<Heap[i]<<" ";
    }
    
    // function call
    // in ths loop we don't include the leaf nodes  
    for(int i = n/2; i> 0; i--)
    {
        Heapify(Heap, n, i);
    }

    cout<<endl<<"After Heapify : "<<endl;
    for(int i =1; i<=n; i++)
    {
        cout<<Heap[i]<<" ";
    }    
    return 0;
}