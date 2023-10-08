#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
Node *tail;

void create_CLL()
{
    Node *temp;
    tail = NULL;
    temp = new Node();
    cout << "Enter Data" << endl;
    cin >> temp->data;
    temp->next = NULL;
    if (tail == NULL)
    {
        tail = temp;
        tail->next = temp;
    }

    else
    {
        temp->next = tail->next;
        tail->next = temp;
        tail = temp;
    }
}

void display_CLL()
{
    Node *temp;
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        temp = tail->next;
        cout << "Circular Linklist is : " << endl;
        while (temp->next != tail->next)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
        cout << " " << temp->data;
    }
}

void insert_beg_CLL()
{

    Node *temp;
    temp = new Node();
    cout << "Enter Data: " << endl;
    cin >> temp->data;
    temp->next = NULL;

    if (tail == NULL)
    { // empty list
        tail = temp;
        tail->next = temp;
    }
    else
    {
        temp->next = tail->next;
        tail->next = temp;
    }
}

int get_length(Node *tail)
{

    int count = 0;
    Node *ptr = tail;
    if (tail != NULL)
    {
        do
        {
            ptr = ptr->next;
            count++;
        } while (ptr != tail);
    }
    return count;
}

void insert_pos_CLL()
{

    Node *temp, *ptr;
    int pos, i, l;
    cout << "Enter the postion for insertion: " << endl;
    cin >> pos;
    l = get_length(tail);
    if (pos < 0 || pos > l)
        cout << "Invalid Position" << endl;
    else if (pos == 1)
        insert_beg_CLL();

    else
    {
        temp = new Node();
        cout << "Enter Data" << endl;
        cin >> temp->data;
        temp->next = NULL;
        ptr = tail->next;
        while (i < pos - 1)
        {
            ptr = ptr->next;
            i++;
        }

        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void delete_beg_CLL()
{

    Node *temp = new Node();
    temp = tail->next;
    if (tail == 0)
    {
        cout << "List is empty " << endl;
    }
    else if (temp->next == temp)
    {
        tail = NULL;
        free(temp);
    }
    else
    {
        tail->next = temp->next;
        free(temp);
    }
}

void delete_end_CLL()
{

    Node *curr, *prev;
    curr = tail->next;
    if (tail == 0)
    {
        cout << "List is empty " << endl;
    }
    else if (curr->next == curr)
    {
        tail = NULL;
        free(curr);
    }
    else
    {
        while (curr->next != tail->next)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = tail->next;
        tail = prev;
        free(curr);
    }
}

void delete_pos_CLL()
{
    Node *curr, *forward;
    int pos, i = 1, l;
    curr = tail->next;
    cout << "Enter Position: " << endl;
    cin >> pos;
    l = get_length(tail);
    if (pos < 1 || pos > l)
    {
        cout << "Invalid Position" << endl;
    }
    else if (pos == 1)
        delete_beg_CLL();
    else
    {
        while (i < pos - 1)
        {
            curr = curr->next;
            i++;
        }
        forward = curr->next;
        curr->next = forward->next;
        free(forward);
    }
}

int main()
{

    int choice;
    while (choice != 9)
    {

        cout << " \n 1.Create" << endl;
        cout << " 2.Display" << endl;
        cout << " 3.Insert at the begining" << endl;
        cout << " 4.Insert at any postion" << endl;
        cout << " 5.Delete at the begining" << endl;
        cout << " 6.Delete at any position" << endl;
        cout << " 7.Delete at the end" << endl;
        cout << " 8. Exit" << endl;
        cout << " Enter your Choice: " << endl;
        cin >> choice;
        switch (choice)
        {

        case 1:
            create_CLL();
            break;

        case 2:
            display_CLL();
            break;

        case 3:
            insert_beg_CLL();
            break;
        case 4:
            insert_pos_CLL();
            break;

        case 5:
            delete_beg_CLL();
            break;

        case 6:
            delete_pos_CLL();
            break;

        case 7:
            delete_end_CLL();
            break;
        case 8:
            exit(0);
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }

    return 0;
}