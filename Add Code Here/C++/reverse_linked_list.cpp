#include <iostream>
#include <vector>

using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int val){
        data = val;
        next = NULL;
    }
};

ListNode* reverse(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    return prev;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    ListNode* newHead = reverse(head);
    while(newHead != NULL){
        cout<<newHead->data<<" ";
        newHead = newHead->next;
    }
    cout<<endl;
    return 0;
}