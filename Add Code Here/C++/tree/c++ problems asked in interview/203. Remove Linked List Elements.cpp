Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []

Solution : 
Time Complexity - O(N) , where N is the number of nodes in the linkedlist 

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==0) //if head is empty 
            return head;
        if(head->val==val) //if value matches 
            return removeElements(head->next,val); //just ignore the element node 
        else
        {
            head->next = removeElements(head->next,val); 
        }
        return head;
    }
};
