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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result=new ListNode();
        ListNode *resultpointer=result;
        int temp=0;
        while(l1!=nullptr || l2!=nullptr)
        {
            int sum=temp;
            if(l1!=nullptr)
            { sum+=l1->val;
              l1=l1->next;
             }
            if(l2!=nullptr) 
            {sum+=l2->val;
             
            l2=l2->next;}
            
            if(sum>9){
                temp=sum/10;
                sum=sum%10;
                
            }
            else{
                temp=0;
            }
            
            resultpointer->next=new ListNode(sum);
           resultpointer=resultpointer->next;
            
        }
        if(temp){
            resultpointer->next=new ListNode(temp);
        }
        return result->next;
    }
};
