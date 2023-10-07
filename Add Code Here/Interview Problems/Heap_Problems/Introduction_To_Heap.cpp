#include<bits/stdc++.h>
using namespace std;
#define max 9999

/*  Following Heap 

                77
              /    \
             60     67
            /  \   /  \
           57  58 51  59        

*/

class Heap
{
    public:
        int arr[max];
        int size;

    // default constructor
    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // Insert function
    void InsertIntoHeap(int val)
    {
        size = size + 1;
        int index = size;

        // insert into the last position
        arr[index] = val;

        // take it to it's right position
        while(1 < index)
        {
            int ParentNode = index / 2;

            if(arr[ParentNode] < arr[index])
            {
                swap(arr[ParentNode], arr[index]);
                index = ParentNode;
            }
            else
            {
                return;
            }
        }
    }

    //


    // print the Heap
    void Display()
    {
        for(int i = 1; i<= size; i++)
        {
            cout<<arr[i]<<" ";
        }

        cout<<endl;
    }

};

int main()
{
    // create the object of heap class
    Heap h;

    h.InsertIntoHeap(60);
    h.InsertIntoHeap(57);
    h.InsertIntoHeap(51);
    h.InsertIntoHeap(67);
    h.InsertIntoHeap(58);
    h.InsertIntoHeap(77);
    h.InsertIntoHeap(59);

    h.Display();

    return 0;
}
