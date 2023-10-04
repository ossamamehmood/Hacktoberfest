#include <bits/stdc++.h>
using namespace std;

/* Link list Node */

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    // Main Logic
    struct Node *reverseList(struct Node *head)
    {
        struct Node *prev, *next, *ptr;
        prev = NULL;
        ptr = head;

        while (ptr != NULL)
        {
            next = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = next;
        }
        head = prev;
        return head;
    }
};

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int n, l, firstdata;

    struct Node *head = NULL, *tail = NULL;

    cout << "Enter the Size of LL : ";
    cin >> n;

    cout << endl
         << "Enter the Root Node of LL : ";
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;

    for (int i = 1; i < n; i++)
    {
        cin >> l;
        tail->next = new Node(l);
        tail = tail->next;
    }

    Solution ob;
    head = ob.reverseList(head);

    printList(head);
    cout << endl;
    return 0;
}
