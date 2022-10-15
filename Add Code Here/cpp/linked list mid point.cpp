//insertion in linked list
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
int length(node *head){
	int cnt=0;
	while(head!=NULL){
		cnt++;
		head=head->next;
	}
	return cnt;
}
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<"--->";
		head=head->next;
	}
}
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
void operator<<(ostream &os,node *head){
	print(head);
	return;
}
int main(){
	node *head=NULL;
	insert_at_head(head,3);
	insert_at_head(head,2);
	insert_at_head(head,1);
	insert_at_head(head,0);
	
	print(head);
	
	node *mid=mid_point(head);
	cout<<endl;
	
	cout<<mid->data;
	
	
}

