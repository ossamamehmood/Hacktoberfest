package Java.Leetcode;

import java.util.ArrayList;
import java.util.List;

//      Q : 78. Subsets
public class Subsets {
    public static void main(String[] args) {
        int[] arr = {1,2,2};
        System.out.println(subsets(arr));
    }
    public static List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> outer = new ArrayList<>();
        outer.add(new ArrayList<>());
        for (int num : nums) {
            int n = outer.size();
            if (num != nums[n]) {
                for (int i = 0; i < n; i++) {
                    List<Integer> inner = new ArrayList<>(outer.get(i));
                    inner.add(num);
                    outer.add(inner);
                }
            }
        }
        return outer;
    }
}
