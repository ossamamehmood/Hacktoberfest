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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
      vector<ListNode*> ans(k,NULL);
      if(!head)
       return ans;
      int len=0;

      ListNode*temp=head;
      while(temp)
      {
          len++;
          temp=temp->next;
      } 
      temp=head;

      int split = len/k;
      int extra = len%k;
      
      int part=0;
      ListNode* next;
      int i=0;
      int m=0;

      while( i<k && temp )
      { 
        m= split-1;
        if( extra >0)
        {
            m=m+1;
            extra--;
        }
        ListNode* sp = temp;
         while( m>0 && temp->next)
         {
             m--;
             temp=temp->next; 
         }
        
         next = temp->next;
         temp->next = NULL;

         ans[i++] = sp;
         temp=next;
      }
      return ans;

    }
};