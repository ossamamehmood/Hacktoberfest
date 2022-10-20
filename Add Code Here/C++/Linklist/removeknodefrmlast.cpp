#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x){
        data=x;
        next=NULL;
    }
};

class Solution
{
public:
    struct Node* deleteList(struct Node* head,int k){
        Node* fast = head;
        Node* slow = head;
 
        for (int i = 0; i < k; i++) {
            fast = fast->next;
        }
 
        if (fast == NULL) {
            head=head->next;
            return;
        }
 
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return;
    }
};


void printList(struct Node *head){
    struct Node *temp=head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}



int main(){
    int T,n,l,firstdata,k;
    cin>>T;
    while (T--){
        struct Node *head =NULL,*tail=NULL;
        cin>>n;
        cin>>firstdata;
        head = new Node(firstdata);
        tail=head;
        for (size_t i = 1; i < n; i++)
        {
            /* code */
            cin>>l;
            tail->next = new Node(l);
            tail=tail->next;
        }
        cin>>k;
        Solution ob;
        head = ob.deleteList(head,k);
        printList(head);
        cout<<endl;
        
    }
    return 0;
}