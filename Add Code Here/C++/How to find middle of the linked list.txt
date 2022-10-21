How to find the middle node of Linked list

1. we will create two variable both initailize with head and 
the one will one by one step the second will go twice

when the second one reached to null the middle is the first variable let's see in the program


Node* MiddleNode(Node* head){
	Node* slow= head;
	Node* fast= head;
	while(fast!=NULL && fast->next!=NULL){
	slow=slow->next;
	fast= fast->next->next;
	}	
	return slow;
}