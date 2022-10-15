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
ostream& operator<<(ostream &os,node *head){
	print(head);
	return os;
}
int main(){
	
	node *head=take_input();
	node *head2=take_input();
	
	print(head);
	cout<<endl;
	print(head2);
	cout<<endl;
	
	node* NewHead=merge(head,head2);
	
	cout<<NewHead<<endl;
	
	return 0;
}
