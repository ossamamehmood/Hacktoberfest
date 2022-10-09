// Github username: kashika1109
// Aim: Merge sort using Linked List in C++
// Date: 10 October 2022


//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/


class Solution{
  public:
    //Function to sort the given linked list using Merge Sort.
Node* midpoint(Node *head){ //MIDPOINT OF LINKED LIST
Node *slow=head;
Node *fast=head->next;
while(fast!=NULL && fast->next!=NULL){
	slow=slow->next;
	fast=fast->next->next;
}
return slow;
}

Node* merge(Node *h1,Node *h2){ //MERGING TWO LINKED LIST
	 if(h1==NULL)
            return h2;
        if(h2==NULL)
            return h1;
	Node *fhead=NULL;
	Node *ftail=NULL;
	if(h1->data <= h2->data){
		fhead=h1;
		ftail=h1;
		h1=h1->next;
		}
		else{
			fhead=h2;
			ftail=h2;
			h2=h2->next;
		}
	while(h1!=NULL && h2!=NULL){
		if(h1->data <= h2->data){
		ftail->next=h1;
		ftail=h1;
		h1=h1->next;
		}
		else{
		ftail->next=h2;
		ftail=h2;
		h2=h2->next;	
		}
	}
	if(h1==NULL){
		ftail->next=h2;
	} else if(h2==NULL){
		ftail->next=h1;
	}
	
	return fhead;
}

Node* mergeSort(Node *head){           //MERGESORT
	if(head==NULL || head->next==NULL) return head;
	Node *mid=midpoint(head); 
	Node *head1=head; 
	Node *head2=mid->next;  
	mid->next=NULL; 
	Node *left_LL=mergeSort(head1); 
	Node *right_LL=mergeSort(head2); 
	Node *finalHead=merge(left_LL,right_LL);
	return finalHead;
}

};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test; //input testcases
    while (test--) { //while testcases exist
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) { 
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a); 
    }
    return 0;
}
// } Driver Code Ends
