// merge two linklist

#include <stdio.h>
#include <stdlib.h>
struct node {
   int data;
   struct node *next;
};
struct node *first = NULL;
struct node *second = NULL;
struct node *list = NULL;
void insert(int data) {
   struct node *link = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   link->data = data;
   link->next = NULL;
   if(data%2 == 0) {
      if(first == NULL) {
         first = link;
         return;
      } 
      else {
         current = first;
         while(current->next != NULL)
         current = current->next;
         current->next = link; 
      }
   } 
   else {
      if(second == NULL) {
         second = link;
         return;
      } else {
         current = second;

         while(current->next!=NULL)
            current = current->next;
        current->next = link; 
      }
   }
}
void display(struct node *head) {
   struct node *ptr = head;
   while(ptr != NULL) {        
      printf(" %d\n",ptr->data);
      ptr = ptr->next;
   }
}
void combine() {
   struct node *link;
   list = first;
   link = list;
   while(link->next!= NULL) {
      link = link->next;
   }
    link->next = second;
}
int main() {
   int i;
    for(i = 1; i <= 10; i++)
        insert(i);
    printf("First list: \n");
    display(first);
    printf("Second list: \n");
    display(second);
    combine();
    printf("Combined List :\n");
    display(list); 
    return 0;
}