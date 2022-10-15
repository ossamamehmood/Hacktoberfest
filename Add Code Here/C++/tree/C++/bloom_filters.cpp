#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Simple Bloom Filter implementation with
// k = 2(hash functions) and m=5(bloom filter's size)

class BloomFilter
{
private:
    int SIZE;
    int bloom[5];

public:

    BloomFilter()
    {
        SIZE = 5;
        for(int i=0 ; i<SIZE ; i++)
            bloom[i] = 0;
    }

    int hash1(int data)
    {
        return (data % SIZE);
    }

    int hash2(int data)
    {
        return (((2*data) + 3) % SIZE);
    }

    void insertElements(int data)
    {
        int index1 = hash1(data);
        int index2 = hash2(data);

        bloom[index1] = 1;
        bloom[index2] = 1;
    }

    bool checkElement(int data)
    {
        int index1 = hash1(data);
        int index2 = hash2(data);

        if((bloom[index1] == 0) || (bloom[index2] == 0))
            return true;
        else
            return false;
    }

    void displayFilter()
    {
        cout<<"\nBloom Filter formed is : "<<endl;
        cout<<"INDEX   BIT"<<endl;
        for(int i=0 ; i<SIZE ; i++)
            cout<<i<<"  --->  "<<bloom[i]<<endl;
    }

};

int main()
{
    BloomFilter b;
    int choice,data;

    while(1)
    {
        cout<<"\n1.Insert \t 2.Check Element \t 3.Display Bloom Filter \t 4.EXIT"<<endl;
        cout<<"Enter choice : ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            {
                cout<<"\nEnter element : ";
                cin>>data;
                b.insertElements(data);

                break;
            }

        case 2:
            {
                cout<<"\nEnter element : ";
                cin>>data;

                bool result = b.checkElement(data);

                if(result == true)
                    cout<<"Element is not present"<<endl;
                else
                    cout<<"Element may be present (FALSE POSITIVE)"<<endl;

                break;
            }

        case 3:
            {
                b.displayFilter();
                break;
            }

        case 4:
            exit(0);
            break;

        default:
            cout<<"\nINVALID CHOICE\n";
        }
    }
    return 0;
}
