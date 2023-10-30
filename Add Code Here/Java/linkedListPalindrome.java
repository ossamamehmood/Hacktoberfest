class Solution {
    public boolean isPalindrome(ListNode head) {
        ListNode start = head;
        ListNode temp = head;
        int size = 1;
        while(temp.next!=null) {
            temp = temp.next;
            size++;
        }
        temp = head;
        for(int i=0; i<size/2; i++) {
            temp = temp.next;
        }
        ListNode curr=temp;
        ListNode prev=null;
        ListNode next;
        while(curr!=null) {
            next=curr.next;
            curr.next=prev;
            prev = curr;
            curr = next;
        }
        ListNode end = prev;
        for(int i=0; i<size/2; i++) {
            if(start.val!=end.val) {
                return false;
            }
            start=start.next;
            end=end.next;
        }
        return true;
    }
  }