//insertion in linked list
#include<iostream>
using namespace std;
class node{
public:
	int data;
	node *next;
	//node constructor
	node(int d){
		data=d;
		next=NULL;
	}
};
//implement using linked class(object oriented)
/*class LinkedList{
	node *head;
	node *tail;
public:
	LinkedList(){
		
	}
	
	void insert(){
		
	}
};*/
//implement using functions(procedurul programming)
void build(){
	
}
//passing the pointer by reference
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
int main(){
	node *head=NULL;
	insert_at_head(head,3);
	insert_at_head(head,2);
	insert_at_head(head,1);
	insert_at_head(head,0);
	
	print(head);
	
}


