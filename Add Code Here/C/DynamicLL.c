#include <stdio.h>
#include <stdlib.h>

enum choice
{
    exited,
    create_Node,
    display_LL,
    insert_node_begin,
    insert_node_pos,
    insert_node_end,
    delete_node_begin,
    delete_node_end,
    delete_node_pos,
    create_LL,
    seek_node
};

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int value, int size);
void display();
void insert_begin();
void insert_pos();
void delete_end();
void delete_begin();
void delete_pos();
void push();
void seek();

int main(void)
{
    int choice;
    do
    {
        printf("/*-/*-/*-/*-/*-/*- Linked List Operations -/*-/*-/*-/*-/*-/*-/\n");
        printf("1. add node\n");
        printf("2. display\n");
        printf("3. Insert Node at beginning\n");
        printf("4. Insert Node in specific position\n");
        printf("5. Insert Node at end of LinkedList\n");
        printf("6. Delete Node at beginning\n");
        printf("7. Delete Node at end\n");
        printf("8. Delete Node at position\n");
        printf("9. create list\n");
        printf("10. seek list\n");
        printf("0. ** To exit **\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case create_Node || insert_node_end:
            int arr = 0;
            create(0, 0);
            printf("choice %d", choice);
            break;
        case display_LL:
            display();
            break;
        case insert_node_begin:
            insert_begin();
            break;
        case delete_node_pos:
            delete_pos();
            break;
        case insert_node_pos:
            insert_pos();
            break;
        case delete_node_begin:
            delete_begin();
            break;
        case delete_node_end:
            delete_end();
            break;
        case create_LL:
            push();
            break;
        case seek_node:
            seek();
            break;
        case exited:
            printf("EXISTING........");
            break;
        default:
            printf("\nWRONG CHOICE\n");
            break;
        }
    } while (choice != exited);

    return 0;
}

void create(int val, int size)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int value;
    if (size != 0)
    {
        value = val;
    }
    else
    {
        printf("Enter Value to be add in the List: ");
        scanf("%d", &value);
    }

    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp; // inserting at end of List
    }
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty");
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("\n%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}

void insert_begin()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("Enter Value to be add in the List: ");
    scanf("%d", &value);

    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    printf("\n");
}
void insert_pos()
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("Enter Value to be add in the List: ");
    scanf("%d", &value);

    temp->data = value;
    temp->next = NULL;

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *prev_ptr;
        struct node *ptr = head;
        int pos;
        printf("Insert Position: ");
        scanf("%d", &pos);
        for (int i = 0; i < pos; i++)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        temp->next = ptr; // inserting at end of List
        prev_ptr->next = temp;
    }
    printf("\n");
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        struct node *ptr = head;
        head = head->next;
        free(ptr);
        printf("NODE DELETED SUCCESSFULLY\n");
    }
}
void delete_end()
{
    if (head == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        struct node *ptr = head;
        struct node *prev_ptr = NULL;
        while (ptr->next != NULL)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = NULL;
        free(ptr);
        printf("NODE DELETED SUCCESSFULLY\n");
    }
}

void push()
{
    int arr[] = {15, 95, 89, 46, 45, 13, 65};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        create(arr[i], size);
    }
    printf("List added successfully\n");
}

void delete_pos()
{
    int pos;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("Linked List is empty\n");
    }
    else if (pos == 0)
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("NODE DELETED SUCCESSFULLY\n");
    }
    else
    {
        struct node *prev_ptr;
        for (int i = 0; i < pos; i++)
        {
            prev_ptr = ptr;
            ptr = ptr->next;
        }
        prev_ptr->next = ptr->next;
        free(ptr);
        printf("NODE DELETED SUCCESSFULLY\n");
    }
}
void seek()
{
    int pos;
    printf("Enter position to seek: ");
    scanf("%d", &pos);
    struct node *ptr = head;
    for (int i = 0; i < pos; i++)
    {
        ptr = ptr->next;
    }
    printf("Item at %d is: %d\n\n", pos, ptr->data);
}