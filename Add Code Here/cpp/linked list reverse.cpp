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
void reverse(node *&head){
	node *current=head;
	node *prev=NULL;
	node *n;
	while(current!=NULL){
		n=current->next;    //save the next node
		current->next=prev;  //make the current node point to previous
		prev=current;  //update previous 1 step forward
		current=n;    //update current 1 step forward
	}
	head=prev;
}
int main(){
	node *head=NULL;
	insert_at_head(head,3);
	insert_at_head(head,2);
	insert_at_head(head,1);
	insert_at_head(head,0);
	
	print(head);
	
	reverse(head);
	
	cout<<endl;
	
	print(head);
	
}


