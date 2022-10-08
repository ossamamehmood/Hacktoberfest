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
//-> Approach One Iter Three Ptr Approach T==o(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head;
        
        ListNode* nxtPtr=head->next;
        ListNode* prevPtr=NULL;
        
        while(head->next)
        {
            head->next=prevPtr;
            prevPtr=head;
            head=nxtPtr;
            if(nxtPtr->next) nxtPtr=nxtPtr->next;
        }
        head->next=prevPtr;
        prevPtr=NULL;
        return head;
    }
};

// Approach 2 --> Recursion 2 ptr

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
void rev(ListNode* prevPtr,ListNode* &head,ListNode* curr)
{
    if(!curr)
    {
        head=prevPtr;
        return;
    }
    
    rev(curr,head,curr->next);
    curr->next=prevPtr;
    
    return;
}
    public:
    ListNode* reverseList(ListNode* head) {
       if(!head) return head;
       
        //ListNode* nxtPtr=head->next;
        ListNode* prevPtr=NULL;
        
        rev(prevPtr,head,head);
        
        return head;
    }
};