// SUSHANT SINHA

// 8ms ( 41.53% ) 238mb ( 14.74% )

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
    public ListNode deleteMiddle(ListNode head) {
        
        int len=0;
        
        ListNode ans=head;
        
        while(head!=null){
            
            head=head.next;
            
            len++;
            
        }
        
        if(len==1){
            
            ans.next=null;
            return ans.next;
            
        }
        
        if(len==2){
            return new ListNode(ans.val);
        }
        
        len/=2;
        
        head=ans;
        
        while(len!=1){
            
            //System.out.println(head.val);
            head=head.next;
            len--;
            
        }
        
        head.next=head.next.next;
        
        return ans;
        
    }
}