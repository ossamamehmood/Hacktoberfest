import java.util.*;

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
        public ListNode[] splitListToParts(ListNode head, int k) {
            int length = 0;
            ListNode current = head;
            List<ListNode> parts = new ArrayList<>();

            while (current != null) {
                length++;
                current = current.next;
            }

            int base_size = length / k, extra = length % k;
            current = head;

            for (int i = 0; i < k; i++) {
                int part_size = base_size + (extra > 0 ? 1 : 0);
                ListNode part_head = null, part_tail = null;

                for (int j = 0; j < part_size; j++) {
                    if (part_head == null) {
                        part_head = part_tail = current;
                    } else {
                        part_tail.next = current;
                        part_tail = part_tail.next;
                    }

                    if (current != null) {
                        current = current.next;
                    }
                }

                if (part_tail != null) {
                    part_tail.next = null;
                }

                parts.add(part_head);
                extra = Math.max(extra - 1, 0);
            }

            return parts.toArray(new ListNode[0]);
        }
    }
}
