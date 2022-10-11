#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};
//----------Linked List-----------//
void insertAtHead(node * &head,int data){
	if(head==NULL){
		head = new node(data);
		return;
	}	
	//otherwise 
	node * n = new node(data);
	n->next = head;
	head = n;
}

void insertInMiddle(node* &head, int data, int pos){
	if(pos==0){
		insertAtHead(head,data);
	}

	else{
		node * temp = head;
		for(int jump=1;jump<=pos-1;jump++){
			temp = temp->next;
		}

		node * n = new node(data);
		n->next = temp->next;
		temp->next = n;

	}
}

node* recReverse(node *head){
	//base case
	if(head==NULL or head->next==NULL){
		return head;
	}
	//otherwise
	node* sHead = recReverse(head->next);
	head->next->next = head;
	head->next = NULL;
	return sHead;
}

void reverse(node *&head){
	node* prev = NULL;
	node* current = head;
	node * temp;

	while(current!=NULL){
		//store next
		temp = current->next;
		//update the current
		current->next = prev;

		//prev and current
		prev = current;
		current = temp;
	}

	head = prev;
	return;
}


node* kReverse(node *head,int k){
	//base case
	if(head==NULL){
		return NULL;
	}

	//reverse the first k nodes
	node* prev = NULL;
	node* current = head;
	node * temp;
	int cnt = 1;

	while(current!=NULL and cnt<=k){
		//store next
		temp = current->next;
		//update the current
		current->next = prev;

		//prev and current
		prev = current;
		current = temp;
		cnt++;
	}

	if(temp!=NULL){
		 head->next = kReverse(temp,k);
	}
	return prev;
}

node* merge(node *a, node* b){
	//Complete this method
	//base case
	if(a==NULL){
		return b;
	}
	if(b==NULL){
		return a;
	}

	//rec case
	node * c;

	if(a->data < b->data){
		c = a;
		c->next = merge(a->next,b);
	}
	else{
		c = b;
		c->next = merge(a,b->next);
	}
	return c;
}

node* midPoint(node *head){

	node * slow = head;
	node * fast = head->next;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


//ToDo : MergeSort
node* mergeSort(node * head){
	//base case
	if(head==NULL or head->next==NULL){
		return head;
	}

	//rec case
	node * mid = midPoint(head);

	//Break at the mid
	node * a = head;
	node * b = mid->next;
	mid->next = NULL;

	//Recursive Sort
	a = mergeSort(a);
	b = mergeSort(b);

	//Merge
	return merge(a,b);

}


void printLL(node * head){

	while(head!=NULL){
		cout <<head->data <<"-->";
		head = head->next;
	}
	cout <<endl;
}


int main(){
	node* a = NULL;
	insertAtHead(a,10);
	insertAtHead(a,7);
	insertAtHead(a,5);
	insertAtHead(a,1);
	insertAtHead(a,17);
	insertAtHead(a,2);
	insertAtHead(a,14);

	printLL(a);

	a = mergeSort(a);

	printLL(a);



	//1-> 5 -> 7 -> 10 -> NULL
	// 2 , 3, 6
	/*
	node* a = NULL;
	insertAtHead(a,10);
	insertAtHead(a,7);
	insertAtHead(a,5);
	insertAtHead(a,1);
	
	node* b = NULL;
	insertAtHead(b,6);
	insertAtHead(b,3);
	insertAtHead(b,2);
	node* head = merge(a,b);
	printLL(head);
	*/

	/*
	node* head = NULL;
	insertAtHead(head,4);
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);
	printLL(head);
	head = kReverse(head,3);
	printLL(head);*/

	return 0;
}
