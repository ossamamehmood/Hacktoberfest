import java.util.*;
public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public int[] maxSlidingWindow(int[] nums, int k) {
            if (nums == null || nums.length == 0 || k <= 0) {
                return new int[0];
            }

            int[] ans = new int[nums.length - k + 1];
            int x = 0;

            Deque<Integer> deque = new LinkedList<>();
            for (int i = 0; i < nums.length; i++) {
                while (!deque.isEmpty() && deque.peek() < i - k + 1) {
                    deque.poll();
                }

                while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
                    deque.pollLast();
                }

                deque.offer(i);

                if (i >= k - 1) {
                    ans[x++] = nums[deque.peek()];
                }
            }

            return ans;
        }
    }

}