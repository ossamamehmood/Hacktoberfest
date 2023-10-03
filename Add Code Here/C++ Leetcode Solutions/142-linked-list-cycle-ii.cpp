/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        unordered_set<ListNode *> u;
        
        ListNode *temp = head;
        
        while(temp){
            
            u.insert(temp);
            temp=temp->next;
            
            if(u.find(temp)!=u.end()) return temp;
        }
        
        return NULL;
    }
};