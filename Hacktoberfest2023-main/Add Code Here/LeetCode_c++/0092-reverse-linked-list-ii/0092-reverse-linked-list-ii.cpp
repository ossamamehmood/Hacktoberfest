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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head==NULL || head->next==NULL || left == right )
         return head;
        
        ListNode* dummy =new ListNode (0,head);
        ListNode* prev=NULL;
        ListNode* curr=dummy;
        
         for(int i=0;i<left;i++)
        {
            prev=curr;
            curr=curr->next;
        }
           ListNode * leftprev=prev;
           ListNode * leftcurr=curr;
        for(int j=left;j<=right;j++)
        {
            ListNode *  frwd=curr->next;
            curr->next=prev;
            prev=curr;
            curr=frwd;
        }
        leftprev->next=prev;
        leftcurr->next=curr;

        return dummy->next;

    }
};