#include <stdio.h>
#include <stdlib.h>
struct node
{
    int row, col;
    float val;
    struct node *link;
} * t1, *t2, *temp, *new1, *prod;

void new_node(int row, int col, float val)
{
    struct node *it = prod;
    if (prod != NULL)
        it = it->link;
    while (it != NULL)
    {
        if (it->row == row && it->col == col)
        {
            it->val += val;
            return;
        }
        it = it->link;
    }

    new1 = (struct node *)malloc(sizeof(struct node));
    new1->row = row;
    new1->col = col;
    new1->val = val;
    new1->link = NULL;
    temp->link = new1;
    temp = new1;
}

void display(struct node *ptr)
{
    temp = ptr;
    while (temp)
    {
        if (temp->val != 0)
            printf("%d %d %.2f\n", temp->row, temp->col, temp->val);
        temp = temp->link;
    }
}

void create(struct node *ptr)
{
    int r, c;
    float v;
    temp = ptr;
    printf("Enter Row, Column, Value for :\n");
    for (int i = 0; i < ptr->val; i++)
    {
    check:
        printf("Input %d: ", i + 1);
        scanf("%d%d%f", &r, &c, &v);
        if (r > ptr->row || c > ptr->col || r < 0 || c < 0)
        {
            printf("Row or Column Exceeded\n");
            goto check;
        }
        new_node(r, c, v);
    }
    printf("\nINPUT :\n");
    display(ptr);
}
//add
void add(struct node *ptr1,struct node *ptr2,int t){
    if(ptr1->row!=ptr2->row && ptr1->col!=ptr2->col){
        printf("Addition Not possible\n");
        return;
    }
    struct node *sum= (struct node *) malloc(sizeof(struct node));
    sum->row=ptr1->row; 
    sum->col=ptr1->col;
    sum->val=0; 
    sum->link=NULL;
    t1=ptr1->link; 
    t2=ptr2->link; 
    temp=sum;
    while(t1!=NULL&&t2!=NULL){
        if(t1->row==t2->row && t1->col==t2->col){
            new_node(t1->row,t1->col,t1->val+t*t2->val);
            t1=t1->link;
            t2=t2->link;
        }
        else if(t1->row<t2->row){
            new_node(t1->row,t1->col,t1->val);
            t1=t1->link;
        }
        else{
            new_node(t2->row,t2->col,t*t2->val);
            t2=t2->link;
        }
        sum->val++;
    }
    while(t1!=NULL){
        new_node(t1->row,t1->col,t1->val);
        t1=t1->link;
        sum->val++;
    }
    while(t2!=NULL){
       new_node(t2->row,t2->col,t*t2->val);
       t2=t2->link;
        sum->val++;
    }
    printf((t==1)?"\nSum :\n":"\nDiff :\n");
    display(sum);
}

//multiply

void mul(struct node *ptr1,struct node *ptr2){
    if(ptr1->col!=ptr2->row){
        printf("Product Not possible\n");
        return;
    }
    prod=(struct node *)malloc(sizeof(struct node));
    prod->row=ptr1->row; prod->col=ptr2->col;
    prod->val=0; prod->link=NULL;
    t1=ptr1->link; temp=prod;
    while(t1!=NULL){
        t2=ptr2->link;
        while(t2!=NULL){
            if(t1->col==t2->row){
                new_node(t1->row,t2->col,(t1->val)*(t2->val));
                prod->val++;
            }
            t2=t2->link;
        }
        t1=t1->link;
    }

    printf("\nProduct of the two sparse matrices is :\n");
    display(prod);
}
int main()
{
    struct node *a, *b, *temp;
    printf("\nMatrix 1 :\n");
    printf("Enter total row, column & non-zero elements : ");
    a = (struct node *)malloc(sizeof(struct node));
    scanf("%d%d%f", &a->row, &a->col, &a->val);
    a->link = NULL;
    create(a);
    printf("\nMatrix 2 :\n");
    printf("Enter total row, column & non-zero elements : ");
    b = (struct node *)malloc(sizeof(struct node));
    scanf("%d%d%f", &b->row, &b->col, &b->val);
    b->link = NULL;
    create(b);
    //add(a,b,1);
    mul(a,b);
    return 0;
}
