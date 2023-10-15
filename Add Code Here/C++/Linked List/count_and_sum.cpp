#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
int Count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    return l;
}
int RCount(struct Node *p)
{
    if (p != NULL)
    {
        return RCount(p->next) + 1;
    }
    return 0;
}
int Sum(struct Node *p){
    int s = 0;
    while(p){
        s = s + p->data;
        p = p->next;
    }
    return s;
}
int RSum(struct Node *p){
    if(p!= NULL){
        return RSum(p->next) + p->data;
    }
    else{
        return 0;
    }
}
int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Create(A, 10);
    // cout << "Length is " << RCount(first);
    cout << "SUM is " << RSum (first);

    return 0;
}