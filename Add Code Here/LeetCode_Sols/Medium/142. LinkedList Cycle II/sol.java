
class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    public class Solution {
        public ListNode detectCycle(ListNode head) {

            ListNode slow = head;
            ListNode fast = head;

            while (fast != null && fast.next != null) {
                slow = slow.next;
                fast = fast.next.next;

                if (fast == slow) {
                    return node(head, slow, fast);
                }
            }

            return null;
        }

        ListNode node(ListNode head, ListNode slow, ListNode fast) {

            slow = head;
            while (slow != fast) {
                slow = slow.next;
                fast = fast.next;
            }

            return slow;
        }
    }
}