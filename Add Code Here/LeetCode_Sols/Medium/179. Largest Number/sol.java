import java.util.*;

public class sol {
    public static void main(String[] args) {
        // call the fn here
    }

    class Solution {
        public String largestNumber(int[] nums) {
            String ans = "";
            ArrayList<String> list = new ArrayList<>();

            for (int i = 0; i < nums.length; i++) {
                list.add(String.valueOf(nums[i]));
            }

            Collections.sort(list, (a, b) -> (b + a).compareTo(a + b));

            for (String s : list) {
                ans += s;
            }

            return ans.charAt(0) == '0' ? "0" : ans;
        }
    }
}