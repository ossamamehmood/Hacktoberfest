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
    while(temp->next!=NULL){
        temp=temp->next;
        cnt++;

    }
    return cnt;
}
void reverse(node *&head){
	node *current=head;
	node *prev=NULL;
	node *n;
	while(current!=NULL){
		n=current->next;    
		current->next=prev;  
		prev=current;  
		current=n;    
	}
	head=prev;
}
node* mid_point(node *&head){
	if(head==NULL or head->next==NULL){
		return head;
	}
	node *slow=head;
	node *fast=head->next;
	while(fast!=NULL and fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;

	
}
bool is_palindrome(node* head){
    if(head==NULL){
        return false;
    }
    node* d=head;
    node* temp=mid_point(head);
    reverse(temp->next);
    node *s=temp->next;
    while(s!=NULL and d!=NULL){
        if(d->data!=s->data){
            return false;
           
        }
        s=s->next;
        d=d->next;
        
    }
    return true;
}

int main() {
    node *head=take_input();
    //print(head);
    if(is_palindrome(head)){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

	return 0;
}

