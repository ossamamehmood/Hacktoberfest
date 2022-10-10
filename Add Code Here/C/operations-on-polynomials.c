#include <stdio.h>
#include <stdlib.h>

struct node{
    int coefficient;
    int power;
    struct node *link;
};

struct node *create(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter coefficient: ");
    scanf("%d",&newnode->coefficient);
    printf("\nEnter power: ");
    scanf("%d",&newnode->power);
    newnode->link=NULL;
    return(newnode);
}

struct node *create_with_value(int coeff, int powr){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coefficient=coeff;
    newnode->power=powr;
    newnode->link=NULL;
    return(newnode);
}

struct node* insert_end(struct node* lhead){
    struct node *temp, *ptr;
    temp=create();
    if(lhead==NULL)
        lhead=temp;
    else{
        ptr=lhead;
        while(ptr->link != NULL)
            ptr = ptr->link;
        ptr->link=temp;
    }
    return(lhead);
}

struct node *insert_end_with_value(struct node *lhead, int coeff, int powr){
    struct node *temp, *ptr;
    temp = create_with_value(coeff, powr);
    if(lhead==NULL)
        lhead=temp;
    else{
        ptr=lhead;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=temp;
    }
    return(lhead);
}

void print(struct node* lhead){
    if(lhead==NULL)
        printf("No Polynomial.");
    else{
        struct node* temp = lhead;
        if(temp->coefficient != 0){
            printf("%dx^%d", temp->coefficient, temp->power);
            temp=temp->link;
        }
        else
            temp=temp->link;
        if(temp->coefficient > 0)
            printf(" + ");
        else if(temp->coefficient < 0)
            printf(" - ");
        while (temp!=NULL){
            if(temp->power!=0){
                if(temp->coefficient > 0){
                    printf("%dx^%d", temp->coefficient, temp->power);
                    temp=temp->link;
                } 
                else if(temp->coefficient < 0){
                    printf("%dx^%d", -temp->coefficient, temp->power);
                    temp=temp->link;
                }
                else
                    temp=temp->link;
                if(temp!=NULL){
                    if(temp->coefficient >= 0)
                        printf(" + ");
                    else
                        printf(" - ");
                }
                else
                    printf("\n");
            }
            else{
                if(temp->coefficient > 0){
                    printf("%d", temp->coefficient);
                    temp=temp->link;
                }
                else if(temp->coefficient < 0){
                    printf("%d", -temp->coefficient);
                    temp=temp->link;
                }
                else
                    temp=temp->link;
                if(temp!=NULL){
                    if(temp->coefficient >= 0)
                        printf(" + ");
                    else
                        printf(" - ");
                }
                else
                    printf("\n");
            }
        }
    }
}

struct node * delete_first(struct node *lhead)
{
	struct node *temp;
	temp = lhead;
	if (lhead == NULL)
		printf("\nList is Empty");
	else if (lhead->link == NULL)
		{
			lhead = NULL;
			free(temp);
		}
	else
		{
			lhead = lhead->link;
			free(temp);
		}
	return(lhead);
}


void add(struct node* head1, struct node* head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->power == ptr2->power){
            head3 = insert_end_with_value(head3, ptr1->coefficient+ptr2->coefficient, ptr1->power);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->power > ptr2->power){
            head3 = insert_end_with_value(head3, ptr1->coefficient, ptr1->power);
            ptr1=ptr1->link;
        }
        else if(ptr1->power < ptr2->power){
            head3 = insert_end_with_value(head3, ptr2->coefficient, ptr2->power);
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL){
        head3=insert_end_with_value(head3, ptr1->coefficient, ptr1->power);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL){
        head3=insert_end_with_value(head3, ptr2->coefficient, ptr2->power);
        ptr2=ptr2->link;
    }

    print(head3);
}

void subtract(struct node* head1, struct node* head2){
    struct node* ptr1=head1;
    struct node* ptr2=head2;
    struct node* head3=NULL;
    while(ptr1!=NULL && ptr2!=NULL){
        if(ptr1->power == ptr2->power){
            head3 = insert_end_with_value(head3, ptr1->coefficient-ptr2->coefficient, ptr1->power);
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if(ptr1->power > ptr2->power){
            head3 = insert_end_with_value(head3, ptr1->coefficient, ptr1->power);
            ptr1=ptr1->link;
        }
        else if(ptr1->power < ptr2->power){
            head3 = insert_end_with_value(head3, -ptr2->coefficient, ptr2->power);
            ptr2=ptr2->link;
        }
    }
    while(ptr1!=NULL){
        head3=insert_end_with_value(head3, ptr1->coefficient, ptr1->power);
        ptr1=ptr1->link;
    }
    while(ptr2!=NULL){
        head3=insert_end_with_value(head3, -ptr2->coefficient, ptr2->power);
        ptr2=ptr2->link;
    }

    print(head3);
}

struct node * removeDuplicate(struct node* head){
    struct node *ptr1, *ptr2, *duplicate;
    ptr1 = head;
    while(ptr1 != NULL && ptr1->link != NULL){
        ptr2=ptr1;
        while(ptr2->link != NULL){
            if(ptr1->power == ptr2->link->power){
                ptr1->coefficient = ptr1->coefficient + ptr2->link->coefficient;
                duplicate = ptr2->link;
                ptr2->link = ptr2->link->link;
                delete_first(duplicate);
            }
            else
                ptr2=ptr2->link;
        }
        ptr1=ptr1->link;
    }
    return(head);
}

void multiply(struct node* head1, struct node* head2){
    struct node *ptr1= head1;
    struct node *ptr2= head2;
    struct node *head3= NULL;
    while(ptr1!=NULL){
        while(ptr2!=NULL){
            int coeff, powr;
            coeff=ptr1->coefficient*ptr2->coefficient;
            powr=ptr1->power+ptr2->power;
            head3=insert_end_with_value(head3,coeff,powr);
            ptr2=ptr2->link;
        }
        ptr2=head2;
        ptr1=ptr1->link;
    }
    removeDuplicate(head3);
    print(head3);
}


void main(){
    int n1, n2;
    char ch;
    struct node *head1=NULL, *head2=NULL;
    printf("Enter the first polynomial: \n");
    printf("Enter the number of terms: \n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++){
        head1=insert_end(head1);
    }
    
    printf("Enter the second polynomial: \n");
    printf("Enter the number of terms: \n");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++){
        head2=insert_end(head2);
    }
    printf("The first polynomial is: \n");
    print(head1);
    printf("The second polynomial is \n");
    print(head2);

    char c='y';
    while(c == 'y'){
        printf("Enter the sign of the operation you want to perform.\n");
        printf("+ for addition\n");
        printf("- for subtraction\n");
        printf("* for multiplication\n");

        scanf(" %c",&ch);
        switch(ch){
        case '+': 
            add(head1,head2);
            break;
        case '-':
            subtract(head1,head2);
            break;
        case '*':
            multiply(head1,head2);
            break;
        default:
            printf("Enter a valid operation.\n");
            break;   
    }
    printf("Do you want to perform another operation? y/n\n");
    scanf(" %c",&c);
    }
   
}
