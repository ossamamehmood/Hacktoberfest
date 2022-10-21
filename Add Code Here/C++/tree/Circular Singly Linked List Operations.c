#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head = NULL ;
struct node* tail = NULL ;

int count = 0;

void display() {
    struct node* display = head;

    if( head == NULL ) {
        printf("\nThe Linked List is empty.\n");
        return;
    }
    printf("\nThe contents of the linked list is: ");
    do {
        printf("%d ",display->data);
        display = display ->next;
    }while( display!= head);
    printf("\n");
}

struct node* getNode(int x){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}

void insertInHead() {
    int x;
    printf("\n Enter the data to insert: ");
    scanf("%d",&x);

    struct node* newnode = getNode(x);

    if ( head == NULL ) {
             head = tail = newnode;
             head->next = head;
    } else {
                newnode->next = head;
                head = newnode;
                tail->next = head;
    }
}

void insertInTail() {

     int x;
    printf("\n Enter the data to insert: ");
    scanf("%d",&x);

    struct node* newnode = getNode(x);

    if ( head == NULL ) {
             head = tail = newnode;
             head->next = head;
    } else {
                tail->next = newnode;
            newnode->next = head;
            tail = newnode;;
    }

}

void insertInN(){
    int x, pos;
    printf("\n Enter the data to insert: ");
    scanf("%d",&x);

    printf("\n Enter the position to insert: ");
    scanf("%d",&pos);

    if( pos<1 || pos>count+1) {
        printf("\n Invalid Position");
        return;
    }

    struct node* newnode = getNode(x);

    if ( pos==1) {
            if ( head == NULL ) {
             head = tail = newnode;
             head->next = head;
            } else {
                newnode->next = head;
                head = newnode;
                tail->next = head;
            }
    }
    else {
        int i;
        struct node* nminus1 = head;

        for(i=1; i<pos-1; i++) {
            nminus1 = nminus1->next;
        }

        if ( nminus1 == tail ) {
            tail->next = newnode;
            newnode->next = head;
            tail = newnode;
        } else {
            newnode->next = nminus1->next;
            nminus1->next = newnode;
        }

    }
    count++;
}

void deleteAtHead() {
    struct node* temp = head;
    if ( head == NULL ) {
            return;
    }
    else if ( head == tail ) {
            free(head);
            head = tail = NULL;
        }else {
            head = head->next;
            tail->next = head;
            free(temp);
        }
        count--;
}

void deleteAtTail() {
    struct node* secondLast = head;
    if ( head == NULL ) {
            return;
    }
    else if ( head == tail ) {
            free(head);
            head = tail = NULL;
        }else {
            while(secondLast->next != tail) {
                secondLast= secondLast->next;
            }
            free(tail);
            tail = secondLast;
            tail->next = head;
        }
        count--;
}

void deleteAtN() {
    if ( head == NULL ) {
            return;
    }

    int pos;
    printf("\n Enter the position for linked list to delete: ");
    scanf("%d",&pos);

    if( pos<1 || pos>count) {
        printf("\n Cannot Delete Invalid Position.");
        return;
    }
    struct node* temp = head;

    if ( pos == 1 ) {
        if ( head == tail ) {
            free(head);
            head = tail = NULL;
        }else {
            head = head->next;
            tail->next = head;
            free(temp);
        }
    } else {

        int i;
        for( i=1; i<pos-1; i++ ) {
            temp = temp ->next;
        }

        if ( temp->next == tail ) {
            free(temp->next);
            tail=temp;
            tail->next = head;
        }
        else {
        struct node* n = temp ->next;
        struct node* nplus1 = temp->next->next;
        temp->next =  nplus1;
        free(n);
        }
    }
    count--;
}

void search() {
    if (head == NULL) {
        return;
    }
    int x;
    printf("\n Enter the element to search in the linked list: ");
    scanf("%d",&x);

    int found = 0 , pos = 1;
    struct node* travel = head;
    do{
        if(travel->data == x) {
            found = 1;
            goto found;
        }
        travel = travel->next;
        pos++;
    }while(travel!=head);

    found:if( found == 1) {
        printf("\n Element found at position %d",pos);
    }else {
        printf("\n Element not found");
    }
}

int main()
{
    int choice;

    while(1) {
    printf("\n Operations For Singly Circular Linked List: ");
    printf("\n Enter 1 for Insertion in Nth Position. ");
    printf("\n Enter 2 for Deletion in Nth Position. ");
    printf("\n Enter 3 for Insertion in Head Position. ");
    printf("\n Enter 4 for Insertion in Tail Position. ");
    printf("\n Enter 5 for Deletion at Head Position. ");
    printf("\n Enter 6 for Deletion at Tail Position. ");
    printf("\n Enter 7 for Displaying the Linked List. ");
    printf("\n Enter 8 for searching in the Linked List. ");
    printf("\n Enter 9 for counting no of element the Linked List. ");
    printf("\n Enter 10 for Exit. ");
    printf("\n Enter your choice: ");
    scanf("%d",&choice);

    switch(choice) {
    case 1:
        insertInN();
        display();
        break;

    case 2:
        deleteAtN();
        display();
        break;

    case 3:
        insertInHead();
        display();
        count++;
        break;

    case 4:
        insertInTail();
        display();
        count++;
        break;

    case 5:
        deleteAtHead();
        display();
        break;

    case 6:
        deleteAtTail();
        display();
        break;

    case 7:
        display();
        break;

    case 8:
        search();
        display();
        break;

    case 9:
        printf("\n No of elements in the linked list: %d",count);
        display();
        break;

    case 10:
        return 0;
    }

    }
    return 0;
}
