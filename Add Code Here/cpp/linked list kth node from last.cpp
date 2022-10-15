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
void insert_at_head(node *&head,int data){
	if(head==NULL){
		head=new node(data);
		return;
	}
	node *n=new node(data);
	n->next=head;
	head=n;
	
}
void print(node *head){
	while(head!=NULL){
		cout<<head->data<<"--->";
		head=head->next;
	}
}
int length(node *head){
	int cnt=0;
	while(head!=NULL){
		cnt++;
		head=head->next;
	}
	return cnt;
}
node* last_k_node(node *head,int k){
	node *slow=head;
	int jump=0;
	while(jump<length(head)-k){
		slow=slow->next;
		jump++;
	}
	return slow;

}
void operator>>(istream &is,node *head){
	print(head);
	return;
}
void operator<<(ostream &os,node *head){
	print(head);
	return;
}
int main(){
	node *head=NULL;
	insert_at_head(head,6);
	insert_at_head(head,5);
	insert_at_head(head,4);
	insert_at_head(head,3);
	insert_at_head(head,2);
	insert_at_head(head,1);
	
	
	print(head);
	int k;
	cin>>k;
	
	node *last=last_k_node(head,k);
	cout<<last->data;
	
}
