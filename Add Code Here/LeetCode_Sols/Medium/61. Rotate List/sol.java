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

    class Solution {
        public ListNode rotateRight(ListNode head, int k) {

            if (head == null || head.next == null) {
                return head;
            }

            int n = 1;
            ListNode temp = head;
            while (temp.next != null) {
                n++;
                temp = temp.next;
            }

            temp.next = head;

            k = k % n;
            k = n - k;
            while (k-- > 0) {
                temp = temp.next;
            }

            head = temp.next;

            temp.next = null;

            return head;
        }
    }

}