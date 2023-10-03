class Solution {
    ListNode * reverse(ListNode * ptr, int &k, int size)
    {
        if(size < k) {
            return ptr;
        }
        if(ptr == NULL){
            return ptr;
        }

        ListNode * cur = ptr;
        ListNode * temp = NULL;
        ListNode * pre = NULL;
        int cnt = 0;
        while(cur!=NULL && cnt < k)
        {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
            cnt++;
        }

        ptr->next = reverse(temp,k,size-k);
        return pre;
    }

    int func(ListNode * ptr)
    {
        int len = 0;
        while(ptr)
        {
            len++;
            ptr = ptr->next;
        }
        return len;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = func(head);
        return reverse(head,k,n);
    }
};