#include<iostream>
using namespace std;
class node{
public:
	int data;
	node* prev;
	node* next;
	
	node(int d){
		data=d;
		prev=NULL;
		next=NULL;
	}
	
	
};
void insert_at_head(node *&head, int data){
	if(head==NULL){
		head=new node(data);
		return;
	}
	node *n=new node(data);
	n->next=head;
	head->prev=NULL;
	
	head=n;
}
/*void insert_at_tail(node *head,int data){
	if(head==NULL){
		head=new node(data);
		return;
	}
	node *n=new node(data);
	
	
}*/

void deletion_at_head(node *head){
	if(head==NULL){
		return;
	}
	delete head;
	node *temp=head->next;
	head=temp;
}
int main(){
	node *head=NULL;
	insert_at_head(head,5);
	insert_at_head(head,4);
	insert_at_head(head,3);
	insert_at_head(head,2);
	insert_at_head(head,1);
	
	print(head);
	
	deletion_at_head(head);
	print(head);
	
	return 0;
}
