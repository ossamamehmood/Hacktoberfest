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

void insertion_at_head(node *&head , int data){
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
bool search(node *head,int key){
	node *temp=head;
	while(temp!=NULL){
		if(head->data==key){
			return true;
		}
		head=head->next;
	}
	return false;
}
//search recursively
bool search_recursively(node *head,int key){
	//base case
	if(head==NULL){
		return false;
	}
	//rec. case
	if(head->data==key){
		return true;
	}
	else{
		return search_recursively(head->next,key);
	}
}

int main(){
	node *head=NULL;
	insertion_at_head(head,1);
	insertion_at_head(head,2);
	insertion_at_head(head,3);
	insertion_at_head(head,4);
	insertion_at_head(head,5);
	
	print(head);
	
	int key;
	cin>>key;
	if(search_recursively(head,key)){
		cout<<"present"<<endl;
	}
	else{
		cout<<"not found"<<endl;
	}
	
	return 0;
}
