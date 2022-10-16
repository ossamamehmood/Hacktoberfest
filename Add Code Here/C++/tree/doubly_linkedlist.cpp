#include<bits/stdc++.h>
using namespace std;

class Node{
	public: 
	   int data;
	   Node* next = NULL;
	   Node* pre = NULL;
};

class LinkedList{
	public: 
	    Node* head = NULL;
	    LinkedList(){
	    	head;
		}
		
		
		Node* temp = head;
		void insert(int val){
		     if(head == NULL){
		     	head = new Node();
		     	head->data = val;
		     	temp = head;
			 }else{
			 	Node* new_node = new Node();
			 	new_node->data = val;
			 	new_node->pre = temp;
			 	temp->next = new_node;
			 	temp = new_node;
			 }
		}
		
		void display(){
			Node* node = head;
			while(node){
				cout<<node->data<<"->";
				node = node->next;
			}
			cout<<endl;
		}
		
		
		void revdisplay(){
			Node* node = temp;
			while(node){
				cout<<node->data<<"->";
				node = node->pre;
			}
			cout<<endl;
		}
		
		void delNode(int pos){
			int t=1;
			if(t == pos){
				Node* n=head;
				head = head->next;
				free(n);
				return;
			}
			Node* node = head;
			Node* prenode = head;
			while(node!= NULL && t!=pos){
				prenode = node;
				node=node->next;
				t++;
			}
			
			if(t<pos){
				return;
			}
			prenode->next = node->next;
			node->next->pre = prenode;
			
			free(node);
			
		}
		
		void insertpos(int val,int pos){
			Node* new_node = new Node();
			new_node->data = val;
			if(pos==1){
			     new_node->next = head;
			     head->pre = new_node;
			     head= new_node;
			     return;
			}
			
			Node* node = head;
			int t=1;
			Node* preNode = head;
			while(node!=NULL && t!=pos){
				preNode = node;
				node = node->next;
				t++;
			}
			
			new_node->next = node;
			node->pre = new_node;
			preNode->next = new_node;
			new_node->pre = preNode;
			return;
		}
		
		
};
int main(){
	
	LinkedList* obj = new LinkedList();
	obj->insert(1);
	obj->insert(2);
	obj->insert(3);
	obj->insert(4);
	obj->insert(5);
	obj->display();
	obj->revdisplay();
	obj->delNode(3);
	obj->display();
	obj->delNode(1);
	obj->display();
	obj->insertpos(1,1);
	obj->display();
	obj->insertpos(3,3);
	obj->display();
	return 0;
	
}
