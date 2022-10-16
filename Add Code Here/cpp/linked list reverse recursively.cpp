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


void insert_at_head(node *&head,int d){
	if(head==NULL){
		head=new node(d);
		return;
	}
	node *n=new node(d);
	n->next=head;
	head=n;
	
}
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<"--->";
		head=head->next;
	}
}
node* reverse_recursively(node *head){
	//for smallest linked list
	if(head->next==NULL or head==NULL){
		return head;
	}
	//recursive case
	node* shead=reverse_recursively(head->next);
	node*temp=head->next;
	temp->next=head;
	/*node* temp=shead;
	while(temp->next!=NULL){       //it would take o(n2) time n for loop and n for recursion
		temp=temp->next;
	}*/
	head->next=NULL;
	temp->next=head;
	return shead;	
	
}
int main(){
	node *head=NULL;
	insert_at_head(head,3);
	insert_at_head(head,2);
	insert_at_head(head,1);
	insert_at_head(head,0);
	
	print(head);
	
	reverse_recursively(head);
	
	cout<<endl;
	
	print(head);
	
}
