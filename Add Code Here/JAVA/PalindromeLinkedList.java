public class PalindromeLinkedList 
{
    public boolean isPalindrome(ListNode head) 
    {
        if(head==null || head.next==null)
        {
            return true;
        }
        
        ListNode fast = head;
        ListNode slow = head;
        
        while(fast.next!=null && fast.next.next!=null)
        {
            slow=slow.next;
            fast=fast.next.next;
        }
        
        slow.next = reverselist(slow.next);
        slow = slow.next;
        ListNode dummy = head;
        
        while(slow!=null)
        {
            if(dummy.val != slow.val)
            {
                return false;
            }
            dummy = dummy.next;
            slow = slow.next;
        }
        
        
        return true;
        
    }
    
    public ListNode reverselist(ListNode node)
    {
        ListNode pre = null;
        ListNode nex = null;
        
        while(node!=null)
        {
            nex = node.next;
            node.next = pre;
            pre = node;
            node = nex;
        }
        
        return pre;
    }
    
}
