#include<bits/stdc++.h>
using namespace std;

#define max 9999

class Heap
{
    public:
    int arr[max];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // 1) Insert Method
    void InsertIntoHeap(int val)
    {
        size = size + 1;
        int index = size;

        // insert into the array
        arr[index] = val;

        // take it to it's right position
        while(index > 1)
        {
            int parent = index / 2;

            if(arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }

    }

    // 2) Delete method
    void DeleteFromHeap()
    {
        // i) base case for empty heap
        if(size == 0)
        {
            cout<<"Nothing to delete from the heap !!"<<endl;
        }

        // ii) copy the last element into the first element
        arr[1] = arr[size];
        size--;

        // iii) take it to it's right position
        int i = 1;
        while(i < size)
        {
            int LeftChild = 2 * i;
            int RightChild = 2 * i + 1;

            if(LeftChild < size && arr[i] < arr[LeftChild])
            {
                swap(arr[i], arr[LeftChild]);
                i = LeftChild;
            }
            else if(RightChild < size && arr[i] < arr[RightChild])
            {
                swap(arr[i], arr[RightChild]);
                i = RightChild;
            }
            else
            {
                return;
            }
        }
    }

    // 3) display method 
    void Display_heap()
    {
        for(int i =1; i<= size; i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }
};

int main()
{
    Heap h;

    h.InsertIntoHeap(40);
    h.InsertIntoHeap(30);
    h.InsertIntoHeap(60);
    h.InsertIntoHeap(44);         
    h.InsertIntoHeap(45);
    h.InsertIntoHeap(54);
    h.InsertIntoHeap(65);

    cout<<"Before Root element Deleting the Heap : "<<endl;
    h.Display_heap();
    
    // deleting the element
    h.DeleteFromHeap();

    cout<<"After Root element Deleting the Heap : "<<endl;
    h.Display_heap();
    return 0;
}