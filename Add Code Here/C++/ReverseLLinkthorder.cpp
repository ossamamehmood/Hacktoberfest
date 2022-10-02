
#include <iostream>
#include <string>
using namespace std;

/////// IMPLEMENTATION OF LINKED LIST   ////////////////////////////
class node
{
public:
    int data;
    node *next; /// pointer of node is to be formed

    // constructor function
    node(int data)
    {
        this->data = data;
        this->next = NULL; 
    }
};

// INSERTION AT HEAD
void insertAthead(node *&head, int d)
{
    // new node created
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

// INSERTION AT TAIL OR END::::
void insertAttail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

/////   INSERTION AT GIVEN INDEXXX :::::::::::::::::
void insertAtpostion(node *tail, node *&head, int position, int d)
{
    if (position == 1)
    {
        insertAthead(head, d);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // creating node for d
    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
    cout << "head = " << head->data << endl;
    cout << "Tail = " << head->data << endl;
}

////  REVERSE LL IN KTH GRP    ////

/// here we are using recursion to solve this
node *reverseKthGRP(node *&head, int k)
{
    // base casee
    if (head == NULL)
    {
        return NULL;
    }
    // step 1 : reverse the first k nodes of ll
    node *next = NULL;
    node *curr = head;
    node *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // STEP 2 : RECURSION DEKLEGA AB
    if (next != NULL)
    {
        head->next = reverseKthGRP(next, k);
    }
    /// STEP 3 : RETURN HEAD OF REVERSED LL
    return prev;
}

// print node
void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    node *node1 = new node(60); // new node node 1

    // head pointed to node1
    node *head = node1;
    // tail pointed to node1
    //  for single node  posityion of tail and head is same
    node *tail = node1;

    // This and  -> is used because it stores the address of data and next node

    // insertion prosecss at head :
    insertAthead(head, 50);

    insertAthead(head, 40);
    insertAthead(head, 30);
    insertAthead(head, 20);
    insertAthead(head, 10);
    print(head);

    /// Kth revers
    int k;
    cout << "Kth ORDER : ";
    cin >> k;
    head = reverseKthGRP(head, k);

    cout << "\nReversed Linked list \n";
    print(head);

    return 0;
}