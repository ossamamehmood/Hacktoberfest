// Implementation of Singly Linked List

// Insertion In Linked List
    // Insert At Beginning
    // Insert At End
    // Insert At Middle

// Deletion In Linked List
    // Delete At Beginning
    // Delete At End
    // Delete At Middle


#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

struct node *newnode, *temp, *Nextnode;

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

void Insert_At_Begin()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    cout<<"Enter the Value to be Inserted At Begin : ";
    cin>>newnode->data;

    newnode->next = head;
    head = newnode;
}

void Insert_At_End()
{
    newnode = (struct node *)malloc(sizeof(struct node));

    cout<<"enter the Data to be insertd At End : ";
    cin>>newnode->data;

    newnode->next = NULL;
    temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void Insert_At_Position(int pos)
{
    newnode = (struct node *)malloc(sizeof(struct node));

    cout<<"enter the Data to be insertd At Position : ";
    cin>>newnode->data;

    int i;
    if(pos == 1)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;

        // we are inserting after the position that's why i = 0
        // Otherwise before position i = 1
        for(i = i; i<pos-1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp ->next;
        temp ->next = newnode;
    }
}

void Delete_At_Begin()
{
    if(head == NULL)
    {
        cout<<"Linked List is Empty !!"<<endl;
    }
    else
    {
        temp = head;
        head = head ->next;

        free(temp);
    }
}

void Delete_At_End()
{
    struct node *Prevnode;

    if(head == NULL)
    {
        cout<<"Linked List is Empty !!"<<endl;
    }
    else
    {
        temp = head;
        while(temp ->next != NULL)
        {
            Prevnode = temp;
            temp = temp->next;
        }

        if(temp == head)
        {
            head = 0;
        }
        else
        {
            Prevnode -> next = 0;
        }

        free(temp);
    }
}

void Delete_At_Position(int pos)
{
    int i = 1;

    struct node *Nextnode;

    temp = head;
    while(i < pos - 1)
    {
        temp = temp ->next;
        i++;
    }

    // Link the (n-1) to (n+1)th Node
    Nextnode = temp->next;
    temp->next = Nextnode->next;

    free(Nextnode);
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
         << "2. INSERT AT BEGIN" << endl
         << "3. INSERT AT END" << endl
         << "4. INSERT AT POSITION " << endl
         << "5. DELETE AT BEGIN" << endl
         << "6. DELETE AT END" << endl
         << "7. DELETE AT POSITION " << endl
         << "8. DISPLAY" << endl
         << "9. EXIT" << endl;
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
                Insert_At_Begin();
                break;
            }

            case 3:
            {
                Insert_At_End();
                break;
            }

            case 4:
            {
                int Position;
                cout<<"\nEnter Position of Node to be Inserted : ";
                cin>>Position;

                Insert_At_Position(Position);
                break;
            }

            case 5:
            {
                Delete_At_Begin();
                break;
            }

            case 6:
            {
                Delete_At_End();
                break;
            }

            case 7:
            {
                int position;
                cout<<"\nEnter Position of Node to be Deleted : ";
                cin>>position;

                Delete_At_Position(position);
                break;
            }

            case 8:
            {
                Display();
                break;
            }

            case 9:
            {
                exit(0);
            }
            default:
            {
                cout << "Error" << endl;
                break;
            }
        }

    } while (n != 9);

    return 0;
}
