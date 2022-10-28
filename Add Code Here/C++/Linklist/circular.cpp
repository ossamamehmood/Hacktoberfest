#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *head;
void createNode(int d)
{
    Node *t;
    Node *new_node = new Node();
    new_node->data = d;
    new_node->next = NULL;

    // if this is first node then
    if (head == NULL)
    {
        head = t = new_node;
        new_node->next = head;
    }
    else
    {
        t->next = new_node;
        t = new_node;
        t->next = head;
    }
}
void display(Node *first)
{
    Node *t = first;
    do
    {
        cout << t->data << " ";
        t = t->next;
    } while (t != first);
}
void AtBegin(int x)
{
    Node *t;
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;

    new_node->next = head;
    head = new_node;
}

int main()
{
    createNode(56);
    createNode(54);
    AtBegin(5);
    display(head);
    return 0;
}
