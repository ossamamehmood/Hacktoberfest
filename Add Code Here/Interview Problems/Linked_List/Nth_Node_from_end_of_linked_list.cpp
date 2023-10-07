#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *newnode, *temp;

void Insert()
{ 
    newnode = (struct node *)malloc(sizeof(struct node *));

    cout<<"Enter the Data to be inserted : ";
    cin>>newnode->data;

    newnode->next = NULL;

    if(head == NULL)
    {
        head = temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}

int getNthNodeFromLast(int k)
{
    struct node *Current;
    
    if(head == NULL)
    {
        return -1;
    }

    int cnt = 0;
    
    temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    int diff = cnt - k;

    if(k > cnt)
    {
        return -1;
    }

    Current = head;
    while(diff--)
    {
        Current =Current->next;
    }

    int ans = Current->data;

    return ans;
}

void Display()
{
    temp = head;

    while( temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp ->next;
    }
    cout<<endl;
}

int main()
{
    int n, val;

    cout << "------------ LINKED LIST IMPLEMENTATION ------------" << endl;

    cout << "1. INSERT " << endl
         << "2. Nth Node" << endl
         << "3. DISPLAY" << endl
         << "4. EXIT" << endl;
    do
    {
        cout << "\nEnter the Choice of Operation : ";
        cin >> n;

        switch (n)
        {
            case 1:
            {
                Insert();
                break;
            }

            case 2:
            {
                int Position;
                cout<<"\nEnter Position To find the Node From End : ";
                cin>>Position;

                cout<<"Node at Position "<<Position<<" is "<<getNthNodeFromLast(Position);
                break;
            }

            case 3:
            {
                Display();
                break;
            }

            case 4:
            {
                exit(0);
            }
            default:
            {
                cout << "Error" << endl;
                break;
            }
        }

    } while (n != 4);

    return 0;
}
