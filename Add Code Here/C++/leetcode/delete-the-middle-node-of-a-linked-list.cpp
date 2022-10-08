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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *temp = NULL;
        temp = head;
        int count = 0;
        while (temp !=NULL)
        {
            count ++;
            temp = temp -> next;
        }
        int n = count / 2, cnt = 0;
        temp = head;
        while (temp != NULL)
        {
            if (cnt == n-1)
            {
                break;
            }
            cnt ++;
            temp = temp -> next;
        }
        ListNode *ptr = NULL;
        if (count == 1)
        {
            head = NULL;
        }
        else
        {
             ptr = temp -> next;
             temp -> next = ptr -> next;
             delete (ptr);
        }
        return head;
    }
};