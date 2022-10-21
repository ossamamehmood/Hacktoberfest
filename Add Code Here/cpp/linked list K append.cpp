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
void insert_at_tail(node *head,int data){
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
void print(node *head){
	if(head==NULL){
		return;
	}
	node *temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
node* take_input(){
	int n;
	cin>>n;
    int d;
	node *head=NULL;
	while(n!=0){
        cin>>d;
        
        insert_at_tail(head,d);
        n--;
    }
    return head;
}
int length(node *head){
    node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;

    }
    return cnt;
}
void K_append(node *head,int K){
    node *prev=head;
    node *current=head->next;
    int jump=0;
    while(jump<=K){
        prev=prev->next;
        current=current->next;
        jump++;
    }
    prev->next=NULL;
    while(current!=NULL){
        current=current->next;
    }
    current->next=head;
}
int main() {
    node *head=take_input();
    int k;
    cin>>k;
    K_append(head,k);
    print(head);

	return 0;
}
