#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head,*s,*temp,*p,*q,*r;
void create(int);
void display();
void insertStart(struct node *,int);
void insertEnd(struct node *,int);
void insertBetween(struct node *,int,int);
int main(){
	int n,ch,num,posval;
	printf("Enter limit of the list: ");
	scanf("%d",&n);
	create(n);
	printf("The list is created\n");
	display();
	printf("Enter choice on where to insert:\n1: At start\n2: At end\n3: Between\n");
	scanf("%d",&ch);
	printf("Number you want to insert: ");
	scanf("%d",&num);
	switch(ch){
		case 1:
			insertStart(head,num);
			break;
		case 2:
			insertEnd(head,num);
			break;
		case 3:
			printf("Enter value before which you want to insert data: ");
			scanf("%d",&posval);
			insertBetween(head,num,posval);
			break;
		default:
			printf("Invalid Choice");
	}
	return 0;
}
void create(int k){
	int i;
	for(i = 0; i<k; i++){
		s = (struct node*)malloc(sizeof(struct node));
		printf("Enter value: ");
		scanf("%d", &s->data);
		if(s == NULL)
			printf("Memory is not allocated");
		else if(i == 0)
			head = temp = s;
		else{
			temp->next = s;
			temp = s;
		}
	}
	temp->next = NULL;
	temp = head;
}
void display(){
	if(temp == NULL)
		printf("List is empty");
	while(temp!=NULL){
		printf("%d\t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void insertStart(struct node *h, int k){
	p = (struct node*)malloc(sizeof(struct node));
	p->data = k;
	p->next = NULL;
	if(h == NULL){
		h=p;
		temp=h;
		display();
	}
	else{
		p->next = h;
		h=p;
		temp=h;
		display();
	}
}
void insertEnd(struct node *h, int k){
	p =(struct node*)malloc(sizeof(struct node));
	p->data = k;
	p->next = NULL;
	q = h;
	while(q->next!=NULL){
		q = q->next;
	}
	q->next = p;
	temp = h;
	display();
}
void insertBetween(struct node *h, int k, int val){
	p = (struct node*)malloc(sizeof(struct node));
	p->data = k;
	p->next = NULL;
	r = q = h;
	while(q->data!= val && q->next!=NULL){
		r = q;
		q = q->next;
	}
	if(q->data == val){
		r->next = p;
		p->next = q;
	}
	temp = h;
	display();
}