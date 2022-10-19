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
//taking input
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
int main(){
	node *head=take_input();

	
	print(head);
	
}

