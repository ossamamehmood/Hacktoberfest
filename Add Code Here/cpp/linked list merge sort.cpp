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
node* take_input(){
	int d;
	cin>>d;
	node *head=NULL;
	while(d!=-1){
		insert_at_head(head,d);
		cin>>d;
	}
	return head;
}
//merge function
node *merge(node *a,node *b){
	//base case
	if(a==NULL){
		return b;
		
	}
	if(b==NULL){
		return a;
	}
	//recursive case
	node *c;
	if(a->data<b->data){
		c=a;
		c->next=merge(a->next,b);
	}
	else{
		c=b;
		c->next=merge(a,b->next);
	}
	return c;
}
//mid point
node* mid_point(node *head){
	if(head==NULL or head->next==NULL){
		return head;
	}
	node *slow=head;
	node *fast=head->next;
	while(fast->next!=NULL and fast!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;

	
}
//merge sort
node* merge_sort(node *head){
	//base case
	if(head==NULL or head->next==NULL){
		return head;
		
	}
	//recuursive case
	//1.divide
	node* mid=mid_point(head);
	node* a=head;
	node* b=mid->next;
	
	mid->next=NULL;
	//2.sort recursively
	a=merge_sort(a);
	b=merge_sort(b);
	//3.merge these sorted parts
	node* c=merge(a,b);
	return c;
	
}
ostream& operator<<(ostream &os,node *head){
	print(head);
	return os;
}
int main(){
	
	node *head=take_input();
	
	
	print(head);
	cout<<endl;
	
	
	head=merge_sort(head);
	cout<<head<<endl;
	

	
	return 0;
}
