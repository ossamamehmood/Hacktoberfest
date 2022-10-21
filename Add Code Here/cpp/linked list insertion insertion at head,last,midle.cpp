#include<iostream>
using namespace std;

class node{
public:
	int data;
	node *next;
	
	node(int d){
		data =d;
		next=NULL;
	}
};
//insert at beginning
void insert_at_head(node *&head,int data){
	if(head==NULL){
		head=new node(data);
		return;
	}
	node *n=new node(data);
	n->next=head;
	head=n;
}
//insert at last
void insert_at_tail(node *&head,int data){
	if(head==NULL){
		head=new node(data);
		return;
	}
	node *tail=head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}
//length of linked list
int length(node *head){
	int cnt=0;
	while(head!=NULL){
		cnt++;
		head=head->next;
	}
	return cnt;
}
//insert at given position
void insert_in_middle(node *&head,int data,int p){
	//corner case
	if(head==NULL or p==0){
		insert_at_head(head,data);
	}
	else if(p>length(head)){
		insert_at_tail(head,data);
		
	}
	else{
		//take p-1 jumps
		int jump=1;
		node *temp=head;
		while(jump<=p-1){
			temp=temp->next;
			jump++;
		}
		//create a new node
		node *n =new node(data);
		n->next=temp->next;
		temp->next=n;
	}
}
//display the list
void print(node *head){
	while(head!=NULL){
		cout<<head->data;
		head=head->next;
	}
}

int main(){
	node *head=NULL;
	insert_at_head(head,5);
	insert_at_head(head,4);
	insert_at_head(head,2);
	insert_at_head(head,1);
	insert_at_head(head,0);
	print(head);
	cout<<endl;
	
	insert_at_tail(head,6);
	insert_in_middle(head,3,3);
	
	print(head);
	
	
}


