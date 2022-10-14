#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *tail;

void implement(int nodes)
{
    tail = NULL;
    int i = 1;
    while (i <= nodes)
    {
        struct node *newnode, *temp;
        newnode = new (struct node);
        cout << "enter the data " << endl;
        cin >> newnode->data;
        newnode->next = 0;
        if (tail == NULL)
        {
            tail = newnode;
            tail->next = newnode; // when it will be a single node due to circular it will store its own adress
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode; //we have updated the tail at last
        }
        i++;
    }
}

void insert_at_begin()
{
    struct node *newnode;
    newnode = new (struct node);
    cout << endl
         << "enter the data " << endl;
    cin >> newnode->data;
    if (tail == NULL)
    {
        tail = newnode;
        newnode->next = tail;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insert_at_end()
{
    struct node *newnode;
    newnode = new (struct node);
    cout << endl
         << "enter the data " << endl;
    cin >> newnode->data;
    if (tail == NULL)
    {
        tail = newnode;
        tail->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void insert_at_pos()
{
    struct node *temp, *newnode;
    int pos;
    int i = 1;
    int l;
    int count = 1;

    { //USED TO FIND THE LENGTH OF THE LIST BEFORE INSERTING AT POSITION
        struct node *length;
        length = tail->next;
        while (length->next != tail->next)
        {
            count++;
            length = length->next;
        }
        cout << endl
             << "Length of link list is " << count;
    }

    cout << endl
         << "ENTER THE POSITION" << endl;
    cin >> pos;
    l = count;
    if (pos < 0 || pos > l)
    {
        cout << endl
             << "Invalid position" << endl;
        ;
    }
    else if (pos == 1)
    {
        insert_at_begin();
    }

    else
    {
        newnode = new (struct node);
        cout << endl
             << "enter the data " << endl;
        cin >> newnode->data;
        newnode->next = 0;
        temp = tail->next;
        while (i < pos - 1)

        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void display()
{
    cout << "PRINTING THE CIRCULAR LINKED LIST" << endl;
    struct node *temp;
    if (tail == 0)
    {
        cout << "LIST IS EMPTY" << endl;
    }
    else
    {
        temp = tail->next; // to assign the value of temp to the first node as tail is containing the adress of first node
        while (temp->next != tail->next)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data; // to print the last data
    }
}

void length()
{
    struct node *temp;
    int count = 1;
    temp = tail->next;
    while (temp->next != tail->next)
    {
        count++;
        temp = temp->next;
    }
    cout << endl
         << "Length of link list is " << count;
}

int main()
{
    int nodes;
    cout << "Enter the number of nodes you want to insert" << endl;
    cin >> nodes;
    implement(nodes);
    display();
    insert_at_pos();
    display();
}
