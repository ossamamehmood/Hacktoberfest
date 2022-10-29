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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k==1 || head == NULL){
            return head;
        }
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        
        ListNode* prev=dummy;
        ListNode* curr=dummy;
        ListNode* nex=dummy;
        
        
        ListNode* temp=head;
        int len=0;
        while(temp != NULL){
            len++;
            temp=temp->next;
        }
        
        while(len >= k){
            curr=prev->next;
            nex=curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next=prev->next;
                prev->next=nex;
                nex=curr->next;
                
            }
            prev=curr;
            len-=k;
        }
        
        return dummy->next;
    }
};
