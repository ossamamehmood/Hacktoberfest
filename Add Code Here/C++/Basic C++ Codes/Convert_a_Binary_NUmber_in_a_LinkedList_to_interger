/**
Question

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

The most significant bit is at the head of the linked list.

 */






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
    int length(ListNode* head ){
    int c=0;
    ListNode* temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->next;
    }
   return c;
    }
    
    int getDecimalValue(ListNode* head) {
        int p=length( head)-1;
        ListNode* temp=head;
        int sum=0;
        
        while(temp!=NULL){
            sum+=(temp->val)*pow(2,p);
            p--;
            temp=temp->next;
        }
        return sum;
    }
};
