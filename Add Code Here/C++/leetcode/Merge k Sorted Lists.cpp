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
 struct compare{
           bool operator()(ListNode* a,ListNode* b){
                return a->val>b->val;
             }
    };
class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        if(lists.size()==1)  return lists[0];
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for(int i=0;i<lists.size();i++){
           if(lists[i]!=NULL) q.push(lists[i]);
        }
        cout<<q.size()<<" ";
        // return NULL;
        if(q.empty()) return NULL;
        ListNode*temp=new ListNode(-1);
        ListNode* head=temp;
        while(!q.empty()){
            head->next=q.top();
           ;
            if(q.top()->next!=NULL){
              ListNode* ptr =q.top()->next;
                q.pop();
                q.push(ptr);
            }  
            else q.pop();
            head=head->next;
        }
        return temp->next;
    }
};