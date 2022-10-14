#include<bits/stdc++.h>
using namespace std;
class node { //define node to store data and next address
   public:
   int data;
   node *next;
};
void display(class node* start) {
   node* p = start; // current node set to head
   while(p != NULL) { //traverse until current node isn't NULL
      cout << p -> data << " ";
      p = p -> next; // go to next node
   }
}
node* getNode(int d) {
   node* temp = new node;
   temp -> data = d;
   temp -> next = NULL;
   return temp;
}
node* mergeList(node* ll1, node* ll2) { //function for merging two sorted list
   node* newhead = NULL;
   if(ll1 == NULL)
      return ll2;
   if(ll2 == NULL)
      return ll1;
   //recursively merge the lists
   if(ll1 -> data <= ll2 -> data) {
      newhead = ll1;
      newhead -> next = mergeList(ll1->next,ll2);
   } else {
      newhead = ll2;
      newhead -> next = mergeList(ll1,ll2->next);
   }
   return newhead;
}
void splitList(node* start, node** ll1,node** ll2) {
   //similar to flyod's tortoise algorithm
   node* slow = start;
   node* fast = start -> next;
   while(fast!= NULL) {
      fast = fast -> next;
      if(fast!= NULL) {
         slow = slow -> next;
         fast = fast -> next;
      }
   }
   *ll1 = start;
   *ll2 = slow -> next;
   //spliting
   slow -> next = NULL;
}
void mergeSort(node** start) {
   node* head = *start;
   node* ll1,*ll2;
   //base case
   if(head == NULL || head->next == NULL) {
      return;
   }
   splitList(head,&ll1,&ll2); //split the list in two halves
   //sort left and right sublists
   mergeSort(&ll1);
   mergeSort(&ll2);
   //merge two sorted list
   *start = mergeList(ll1,ll2);
   return;
}
int main() {
   cout << "Creating the linked list: " << endl;
   cout << "Enter 0 to stop building the list, else enter any integer" << endl;
   int k,count = 1,x;
   node* curr,*temp;
   cin >> k;
   node* head = getNode(k);   //buliding list, first node
   cin >> k;
   temp = head;
   while(k) {
      curr = getNode(k);
      temp -> next = curr;//appending each node
      temp = temp -> next;
      cin >> k;
   }
   cout<<"Before sorting: " << endl;
   display(head); // displaying the list
   cout<<"\nAfter sorting: " << endl;
   mergeSort(&head);
   display(head);
   return 0;
}