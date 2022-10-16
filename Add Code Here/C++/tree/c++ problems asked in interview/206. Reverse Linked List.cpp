Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]
Example 3:

Input: head = []
Output: []

Solution :
Time Complexity : O(n) 
Space Complexity : O(n) where n is the size of the linkedlist

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int>res;
        ListNode* temp = head;
        while(temp)
        {
            res.push_back(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        
        for(int i=res.size()-1; i>=0;i--)
        {
            temp->val = res[i];
            temp =temp->next;
        }
        return head;
    }
};
