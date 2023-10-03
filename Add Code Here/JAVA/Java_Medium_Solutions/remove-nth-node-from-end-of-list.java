/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
          if (head.next == null) {
            return null;
        }

        //To Find the Size
        int size = 0;
        ListNode curr = head;
        while (curr!= null){
            curr = curr.next;
            size++;
        }

        if (n == size){
            return head.next;
        }

        //To search and Delete
        int index = size - n;
        ListNode prev = head;
        for(int i =1; i < index; i++){
            prev = prev.next;
        }
        prev.next = prev.next.next;  //skipping the node or unlinking the node
        return head;
        
    }
}
