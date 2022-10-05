/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int length(ListNode *head){
        int len=0;
        while(head){
            len++;
            head=head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(length(head)<k)   return head;
        ListNode *prev=NULL,*curr=head;
        for(int i=0;i<k;i++){
            ListNode *n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;   
        }
        head->next=reverseKGroup(curr,k);
        return prev;
    }
};
