Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

Solution:

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* temp = res;
        
        while(l1 && l2){
            if(l1->val <l2->val){
                temp->next = l1;
                l1 = l1->next ; 
            }
            
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) temp->next = l1;
        if(l2) temp->next = l2;
        
        return res->next;
    }
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) //in case only one linkedlist exists 
            return l2;
        if(l2==NULL)  //in case only one linkedlist exists 
            return l1;
        
        if(l1->val >= l2->val)  // if value in l1 is greater 
            l2->next = mergeTwoLists(l1,l2->next); //pass l1 value but for l2 iterate to the next value
        else
        {
            l1->next = mergeTwoLists(l1->next,l2);
            l2=l1;
        }
        return l2;
    }
};
