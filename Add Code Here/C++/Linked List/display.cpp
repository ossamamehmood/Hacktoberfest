#include <iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first = NULL;
void Create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = new Node();
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(i =1; i<n ; i++){
        t = new Node();
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last =t;
    }
}
void Display(struct Node *p)
{
 while(p!=NULL)
 {
 printf("%d ",p->data);
 p=p->next;
 }
}
void RDisplay(struct Node *p)
{
 if(p!=NULL)
 {
 RDisplay(p->next);
 printf("%d ",p->data);

 }
}
int main(){
   int A[] = {0,1,2,3,4,5,6,7,8,9};
Create(A, 10);
RDisplay(first);
    return 0;
}