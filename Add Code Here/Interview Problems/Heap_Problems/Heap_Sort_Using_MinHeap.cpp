#include<bits/stdc++.h>
using namespace std;

void Heapify(int heap[], int n, int i)
{
    int smallest = i;
    int Left = 2 * i + 1;
    int Right = 2 * i + 2;

    if(Left < n && heap[smallest] > heap[Left])
    {
        smallest = Left;
    }

    if(Right < n && heap[smallest] > heap[Right])
    {
        smallest = Right;
    }

    if(smallest != i)
    {
        swap(heap[smallest], heap[i]);

        Heapify(heap, n, smallest);
    }

}

void BuildHeap(int Heap[], int n)
{
    for(int i = n/2-1; i>=0; i--)
    {
        Heapify(Heap, n, i);
    }
}

void HeapSort(int Heap[], int n)
{
    for(int i = n-1; i>= 0; i--)
    {
        swap(Heap[i], Heap[0]);

        Heapify(Heap, i, 0);
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
    
    // function call for build heap
    BuildHeap(Heap, n);

    cout<<endl<<"After Heapify : "<<endl;
    for(int i =0; i<n; i++)
    {
        cout<<Heap[i]<<" ";
    }
    cout<<endl;  

    // function call for heap sort
    HeapSort(Heap, n);
    
    cout<<endl<<"After Heap Sort : "<<endl;
    for(int i =0; i<n; i++)
    {
        cout<<Heap[i]<<" ";
    }  
    cout<<endl;

    return 0;
}