#include<bits/stdc++.h>
using namespace std;

void Heapify(int heap[], int n, int i)
{
    int largest = i;
    int Left = 2 * i;
    int Right = 2 * i + 1;

    if(Left <= n && 
    heap[largest] < heap[Left])
    {
        largest = Left;
    }

    if(Right <= n && heap[largest] < heap[Right])
    {
        largest = Right;
    }

    if(largest != i)
    {
        swap(heap[largest], heap[i]);

        Heapify(heap, n, largest);
    }

}

void BuildHeap(int Heap[], int n)
{
    for(int i = n/2; i>0; i--)
    {
        Heapify(Heap, n, i);
    }
}

void HeapSort(int heap[], int n)
{
    int size = n;

    while(size > 1)
    {
        // step 1: swap the first and last element
        swap(heap[size], heap[1]);
        size--;

        // step 2: check remaining heap follwing the heap property or not
        Heapify(heap, size, 1);
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
    
    // function call for build heap
    BuildHeap(Heap, n);

    cout<<endl<<"After Heapify : "<<endl;
    for(int i =1; i<=n; i++)
    {
        cout<<Heap[i]<<" ";
    }
    cout<<endl;  

    // function call for heap sort
    HeapSort(Heap, n);
    
    cout<<endl<<"After Heap Sort : "<<endl;
    for(int i =1; i<=n; i++)
    {
        cout<<Heap[i]<<" ";
    }  
    cout<<endl;

    return 0;
}