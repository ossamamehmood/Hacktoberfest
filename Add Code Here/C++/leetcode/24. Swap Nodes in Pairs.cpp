class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
     if(!head||!head->next)
       return head;
    
        ListNode* curr=head->next->next;
        ListNode* prev=head;
        head=head->next;
        head->next=prev;
        
        while(curr&&curr->next)
        {
            prev->next=curr->next;
            prev=curr;
            ListNode*temp=curr->next->next;
            curr->next->next=prev;
            curr=temp;
            
        }
            prev->next=curr;
        return head;
       
        
    }
};
