public class cyclecheckLL {
    public boolean hasCycle(ListNode head) {
        while(head!=null){
            if(head.val==1000000){
                return true;
            }
            head.val=1000000;
            head=head.next;
        }
        return false;
    }
}
