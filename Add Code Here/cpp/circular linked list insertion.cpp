#include<iostream>
using namespace std;
class node{
public:
	int data;
	node *next;
	
	node(int d){
		data=d;
		next=NULL;
	}
};
void insertion_at_head(node *&head,int data){
	//1.create a new node
	node *n=new node(data);
	node *temp=head;
    n->next=head;
	//2.if list is not empty than traverse the list till last node and updat the pointer of last node to the new node
	if(temp!=NULL){
		while(temp->next!=head){
			
			temp=temp->next;
		}
		temp->next=n;
	}
	//if list is empty then new node poins to itself
	else{
		n->next=n;
	}
	//update head to new node
	head=n;
}
void print(node *head){
	node *temp=head;
	while(temp->next!=head){
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<temp->data<<"  ";
}
int main(){
	node *head=NULL;
	insertion_at_head(head,1);
	insertion_at_head(head,2);
	insertion_at_head(head,3);
	insertion_at_head(head,4);
	print(head);
	return 0;
}
